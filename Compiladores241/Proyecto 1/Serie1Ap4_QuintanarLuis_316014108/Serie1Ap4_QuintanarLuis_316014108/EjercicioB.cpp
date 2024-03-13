#include "EjercicioB.hpp"

void EjercicioB::iniciarB()
{
	i = -1;
	cout << "Dame la cadena que analizaremos lexicamente:" << endl;
	cin >> cadena;
	estado0B();
}
void EjercicioB::estado0B()
{
	i++;
	if ((cadena[i]) == 'a')
		estado1B();
	else
		cout << "Cadena NO valida" << endl;
}
void EjercicioB::estado1B()
{
	i++;
	if ((cadena[i]) == 'a')
		estado2B();
	else
		if ((cadena[i]) == 'b')
			estado3B();
		else
			cout << "Cadena NO valida" << endl;
}
void EjercicioB::estado2B()
{
	i++;
	if ((cadena[i]) == 'a')
		estado2B();
	else
		if ((cadena[i]) == 'b')
			estado3B();
		else
			cout << "Cadena NO valida" << endl;
}
void EjercicioB::estado3B()
{
	i++;
	if ((cadena[i]) == 'a')
		estado4B();
	else
		cout << "Cadena NO valida" << endl;
}
void EjercicioB::estado4B()
{
	i++;
	if ((cadena[i]) == 'b')
		estado3B();
	else
		if (cadena[i] == '\0')
			cout << "Cadena Valida" << endl;
		else
			cout << "Cadena NO valida" << endl;
}
