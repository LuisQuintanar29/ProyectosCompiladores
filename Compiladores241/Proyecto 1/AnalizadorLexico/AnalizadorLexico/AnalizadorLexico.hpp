#ifndef __AnalizadorLexico_HPP__
#define __AnalizadorLexico_HPP__

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <sstream>
#include <algorithm>

#include "Tokens.hpp"

using namespace std;

class AnalizadorLexico
{
	public:
		AnalizadorLexico() = default;
		AnalizadorLexico(string fileName);
		~AnalizadorLexico() = default;
        map <string, int> tablaSimbolos = {};
        int tablaToken = 0;
		void error(string msg);
	private:
		ifstream file;
        TOKEN token;
		vector<string> tipoDato =
		{
			"int",
			"float",
			"char",
			"void",
			"short",
			"long",
			"double",
			"enum",
			"struct",
			"bool"
		};
		vector<string> palabrasReservadas = 
		{
			"printf",
			"scanf",
			"switch",
			"case",
			"break",
			"while",
			"for",
			"if",
			"else",
			"return",
			"enum",
			"struct",
			"default",
			"sizeof",
			"do",
		};
		vector<char> simbolosEspeciales=
		{
			';',
			'{',
			'}',
			',',
			']',
			'(',
			')',
			'[',
		};
		vector<char> operadores =
		{
			'=',
			'+',
			'-',
			'*',
			'/',
			'%',
			'&',
			'>',
			'<',
		};
		vector<char> espacios =
		{
			'\n',
			' ',
			'\t',
			'\r',
			'\f',
			'\v',
		};
		int lineas = 0;
		void openFile(string fileName);
		void printFile(string fileTable, string text);
        void ordenaTablaSimbolos();
        void construyeTablas(string buffer, claseToken tipoToken);
		void closeFile();
        void queEs(string cad);
		bool esEntero(string cad);
		bool esReal(string cad);
		bool esPalabraReservada(string cad);
		bool esTipoDato(string cad);
		bool esCadena(string cad);
		bool esCaracter(string cad);
		bool esIdentificador(string cad);
		bool esOperador(char car);
		bool esSimboloEspecial(char car);
		bool esEspacio(char car);

};
AnalizadorLexico::AnalizadorLexico(string fileName)
{
    openFile(fileName);
    remove("tablaSimbolos.txt");
    remove("tablaTokens.txt");
    string buffer = "";
    string linea = "";
    bool cadena = false;

    while (!file.eof())
    {
        getline(file, linea);
        lineas++;
        for (size_t i = 0; i < linea.size(); i++)
        {
            if (!esEspacio(linea[i]) && !esSimboloEspecial(linea[i]) && !esOperador(linea[i]) && linea[i] != '\"')
                buffer.append(1, linea[i]);
            else
                if (linea[i] == '\"' && cadena)
                {
                    cadena = false;
                    buffer.append(1, linea[i]);
                }
                else
                    if (linea[i] == '\"' && !cadena)
                    {
                        cadena = true;
                        buffer.append(1, linea[i]);
                    }
                    else
                        if (cadena)
                            buffer.append(1, linea[i]);
                        else
                        {
                            if (esEspacio(linea[i]))
                                if (buffer.size() == 0)
                                {
                                    construyeTablas(buffer.append(1, linea[i]), espacio);
                                }
                                else
                                {
                                    queEs(buffer);
                                }
                            else
                            {
                                if (esOperador(linea[i]))
                                    if (buffer.size() == 0) construyeTablas(buffer.append(1, linea[i]), operador);
                                    else
                                    {
                                        queEs(buffer);
                                        buffer = "";
                                        construyeTablas(buffer.append(1, linea[i]), operador);
                                    }
                                else
                                    if (esSimboloEspecial(linea[i]))
                                        if (buffer.size() == 0) construyeTablas(buffer.append(1, linea[i]), simboloEspecial);
                                        else
                                        {
                                            queEs(buffer);
                                            buffer = "";
                                            construyeTablas(buffer.append(1, linea[i]), simboloEspecial);
                                        }
                                    else
                                        queEs(buffer);
                            }
                            buffer = "";
                        }
        }
    }
    ordenaTablaSimbolos();
}
void AnalizadorLexico::printFile(string fileTable, string text)
{
    ofstream fich{ fileTable, ios::app };
    if (!fich)
    {
        cout << "Error al abrir " << fileTable << endl;
        exit(EXIT_FAILURE);
    }
    fich << text << endl;
    fich.close();
}
void AnalizadorLexico::openFile(string filename)
{
    file.open(filename, ios::in);
    if (!file.is_open()) error("El archivo no se encuentra");
}
void AnalizadorLexico::error(string msg)
{
    cout << msg << endl;
    closeFile();
    exit(EXIT_FAILURE);
}
void AnalizadorLexico::construyeTablas(string buffer, claseToken tipoToken)
{
    string txt = "";
    switch (tipoToken)
    {
    case palabraReservada:
        if (!tablaSimbolos.count(buffer))
        {
            tablaSimbolos.insert(pair<string, int>(buffer, tablaSimbolos.size() + 1));
            txt = "( 0 , " + to_string(tablaSimbolos.size()) + " )";
            printFile("tablaTokens.txt", txt );
        }
        else
        {
            txt = "( 0 , " + to_string(tablaSimbolos[buffer]) + " )";
            printFile("tablaTokens.txt", txt);
        }
            
        break;
    case identificador:
        if (!tablaSimbolos.count(buffer))
        {
            tablaSimbolos.insert(pair<string, int>(buffer, tablaSimbolos.size() + 1));
            txt = "( 1 , " + to_string(tablaSimbolos.size()) + " )";
            printFile("tablaTokens.txt", txt);
        }
        else
        {
            txt = "( 1 , " + to_string(tablaSimbolos[buffer]) + " )";
            printFile("tablaTokens.txt", txt);
        }
        break;
    case entero:
        txt = "( 2 , " + buffer +  " )";
        printFile("tablaTokens.txt", txt);
        break;
    case real:
        txt = "( 3 , " + buffer + " )";
        printFile("tablaTokens.txt", txt);
        break;
    case operador:
        txt = "( 4 , " + buffer + " )";
        printFile("tablaTokens.txt", txt);
        break;
    case simboloEspecial:
        txt = "( 5 , " + buffer + " )";
        printFile("tablaTokens.txt", txt);
        break;
    case cadena:
        txt = "( 6 , " + buffer + " )";
        printFile("tablaTokens.txt", txt);
        break;
    case caracter:
        txt = "( 7 , " + buffer + " )";
        printFile("tablaTokens.txt", txt);
        break;
    case espacio:
        break;
    case tipoDeDato:
        if (!tablaSimbolos.count(buffer))
        {
            tablaSimbolos.insert(pair<string, int>(buffer, tablaSimbolos.size() + 1));
            txt = "( 8 , " + to_string(tablaSimbolos.size()) + " )";
            printFile("tablaTokens.txt", txt);
        }
        else
        {
            txt = "( 8 , " + to_string(tablaSimbolos[buffer]) + " )";
            printFile("tablaTokens.txt", txt);
        }
        break;
    case errorLexico:
        cout << buffer + " es Error Lexico\n";
        break;
    default:
        break;
    }
}
void AnalizadorLexico::ordenaTablaSimbolos()
{

    // crea un vector vacío de pares
    vector<pair<std::string, int>> vec;

    // copia pares clave-valor del mapa al vector
    copy(tablaSimbolos.begin(),
        tablaSimbolos.end(),
        std::back_inserter<std::vector<pair<std::string, int>>>(vec));

    // ordenar el vector aumentando el orden del segundo valor de su par
    // si el segundo valor es igual, ordena por el primer valor del par
    std::sort(vec.begin(), vec.end(),
        [](const pair<std::string, int>& l, const pair<std::string, int>& r)
        {
            if (l.second != r.second) {
                return l.second < r.second;
            }

            return l.first < r.first;
        });
    for (auto const& pair : vec) {
        string text = to_string(pair.second) + "\t\t\t" + pair.first ;
        printFile("tablaSimbolos.txt", text);
    }
}
void AnalizadorLexico::closeFile()
{
    if (file.is_open()) file.close();
}
void AnalizadorLexico::queEs(string buffer)
{
    if (esPalabraReservada(buffer)) construyeTablas(buffer, palabraReservada);
    else
        if (esTipoDato(buffer)) construyeTablas(buffer, tipoDeDato);
        else
            if (esCadena(buffer)) construyeTablas(buffer, cadena);
            else
                if (esIdentificador(buffer)) construyeTablas(buffer, identificador);
                else
                    if (esEntero(buffer)) construyeTablas(buffer, entero);
                    else
                        if (esReal(buffer)) construyeTablas(buffer, real);
                        else
                            if (esCaracter(buffer)) construyeTablas(buffer, caracter);
                            else
                               cout << "Error Lexico: " + buffer + " en linea " + to_string(lineas) << endl;
}
bool AnalizadorLexico::esEntero(string cad)
{
    if (cad.empty()) return false;

    size_t startIndex = 0;
    if (cad[0] == '-' || cad[0] == '+')
        startIndex = 1;
    for (size_t i = startIndex; i < cad.length(); ++i)
        if (!std::isdigit(cad[i]))
            return false;
    return true;
}
bool AnalizadorLexico::esReal(string cad)
{
    if (cad.empty()) return false;
    size_t startIndex = 0;
    bool puntoEncontrado = false;
    if (cad[0] == '-' || cad[0] == '+')
        startIndex = 1;
    for (size_t i = startIndex; i < cad.length(); ++i)
        if (cad[i] == '.')
            if (puntoEncontrado) return false;
            else puntoEncontrado = true;
        else
            if (!isdigit(cad[i]))
                return false;
    return true;
}
bool AnalizadorLexico::esCadena(string cad)
{
    if (cad.size() >= 2 && cad[0] == '"' && cad[cad.size() - 1] == '"') return true;
    return false;
}
bool AnalizadorLexico::esCaracter(string cad)
{
    if (cad[0] == '\'' && cad[cad.size() - 1] == '\'' && cad.size() == 3) return true;
    return false;
}
bool AnalizadorLexico::esIdentificador(string cad)
{
    if (cad[0] != '_' && !((cad[0] >= 'A' && cad[0] <= 'Z') || (cad[0] >= 'a' && cad[0] <= 'z'))) return false;
    for (size_t i = 1; i < cad.size(); i++)
    {
        if (cad[i] != '_' && !((cad[i] >= 'A' && cad[i] <= 'Z') || (cad[i] >= 'a' && cad[i] <= 'z') || (cad[i] >= '0' && cad[i] <= '9'))) return false;
    }
    return true;
}
bool AnalizadorLexico::esPalabraReservada(string cad)
{
    for (size_t i = 0; i < palabrasReservadas.size(); i++)
        if (palabrasReservadas[i] == cad) return true;
    return false;
}
bool AnalizadorLexico::esTipoDato(string cad)
{
    for (size_t i = 0; i < tipoDato.size(); i++)
        if (tipoDato[i] == cad) return true;
    return false;
}
bool AnalizadorLexico::esOperador(char car)
{
    for (size_t i = 0; i < operadores.size(); i++)
        if (operadores[i] == car) return true;
    return false;
}
bool AnalizadorLexico::esSimboloEspecial(char car)
{
    for (size_t i = 0; i < simbolosEspeciales.size(); i++)
        if (simbolosEspeciales[i] == car) return true;
    return false;
}
bool AnalizadorLexico::esEspacio(char car)
{
    for (size_t i = 0; i < espacios.size(); i++)
        if (car == espacios[i]) return true;
    return false;
}


#endif // __AnalizadorLexico_HPP__
