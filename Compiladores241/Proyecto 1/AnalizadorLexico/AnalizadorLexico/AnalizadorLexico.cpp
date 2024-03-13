/******************* Proyecto 1. Analizador Léxico *******************/
/*********** Nombre: Quintanar Ramírez Luis Enrique ***********/
/*********** Cuenta: 316014108 ***********/
// Elaborar un programa que analice léxicamente un archivo de código fuente


// Coregir esCadena, esOperador y esSimboloEsp cuando el buffer tiene más caracteres
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
