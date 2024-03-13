#include "EjercicioD.hpp"

void EjercicioD::iniciarD()
{
	string aux;
	i = -1;
	getchar();
	cout << "Dame la cadena que analizaremos lexicamente:" << endl;
	aux = getchar();
	if(aux[0] == '\n')
		cout << "Cadena Valida" << endl;
	else
	{
		cin >> cadena;
		cadena = aux = aux + cadena;
		estado0D();
	}
}
void EjercicioD::estado0D()
{
	i++;
	if ((cadena[i]) == '1')
		estado1D();
	else
		cout << "Cadena NO valida" << endl;
}
void EjercicioD::estado1D()
{
	i++;
	if ((cadena[i]) == '2')
		estado2D();
	else
		cout << "Cadena NO valida" << endl;
}
void EjercicioD::estado2D()
{
	i++;
	if ((cadena[i]) == '3')
		estado3D();
	else
		if ((cadena[i]) == '4')
			estado4D();
		else
			cout << "Cadena NO valida" << endl;
}
void EjercicioD::estado3D()
{
	i++;
	if ((cadena[i]) == '3')
		estado3D();
	else
		if ((cadena[i]) == '4')
			estado4D();
		else
			cout << "Cadena NO valida" << endl;
}
void EjercicioD::estado4D()
{
	i++;
	if ((cadena[i]) == '5')
		estado5D();
	else
		cout << "Cadena NO valida" << endl;
}
void EjercicioD::estado5D()
{
	i++;
	if ((cadena[i]) == '6')
		estado6D();
	else
		cout << "Cadena NO valida" << endl;
}
void EjercicioD::estado6D()
{
	i++;
	if ((cadena[i]) == '6')
		estado6D();
	else
		if ((cadena[i]) == '\0')
			cout << "Cadena Valida" << endl;
		else
			cout << "Cadena NO valida" << endl;
}