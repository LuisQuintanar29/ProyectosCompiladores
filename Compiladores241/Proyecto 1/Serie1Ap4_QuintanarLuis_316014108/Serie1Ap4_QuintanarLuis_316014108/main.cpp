#include "EjercicioB.hpp"
#include "EjercicioD.hpp"
#include "Ejercicioi.hpp"

int main() 
{
	int opcion;
	EjercicioB B;
	EjercicioD D;
	EjercicioI I;
	do {
		cout << "\n\nAnalizador lexico a partir del diagrama de estados\n"
			<< "Seleccione el ejercicio para analizar la cadena con las siguientes ER\n" 
			<< "[1]: aa*(ba)+ \t\t\t Apartado 1, inciso b) \n"
			<< "[2]: (123*456+)? \t\t Apartado 1, inciso d) \n"
			<< "[3]: aba*ba*ba* \t\t Apartado 1, inciso i) \n"
			<< "[4]: Salir\n"
			<< endl;
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			B.iniciarB();
			break;
		case 2:
			D.iniciarD();
			break;
		case 3:
			I.iniciarI();
			break;
		default:
			break;
		}
	} while (opcion != 4);
	
	return 0;
}