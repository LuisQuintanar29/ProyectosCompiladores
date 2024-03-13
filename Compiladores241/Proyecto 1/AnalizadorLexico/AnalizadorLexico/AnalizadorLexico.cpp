/******************* Proyecto 1. Analizador L�xico *******************/
/*********** Nombre: Quintanar Ram�rez Luis Enrique ***********/
/*********** Cuenta: 316014108 ***********/
// Elaborar un programa que analice l�xicamente un archivo de c�digo fuente


// Coregir esCadena, esOperador y esSimboloEsp cuando el buffer tiene m�s caracteres
#include "AnalizadorLexico.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cout << "Faltan argumentos a main" << std::endl;
        return -1;
    }
    AnalizadorLexico AL(argv[1]);
    return 0;
}
