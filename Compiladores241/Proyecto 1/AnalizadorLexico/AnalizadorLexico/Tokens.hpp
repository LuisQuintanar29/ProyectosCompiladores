#ifndef __TOKENS_HPP__
#define __TOKENS_HPP__
#include <string>

enum claseToken
{
    palabraReservada = 0,
    identificador,
    entero,
    real,
    operador,
    simboloEspecial,
    cadena,
    caracter,    
    tipoDeDato,
    errorLexico,
    espacio,
    fin
};
struct TOKEN 
{
    claseToken tipo;
};

#endif // !__TOKENS_HPP__