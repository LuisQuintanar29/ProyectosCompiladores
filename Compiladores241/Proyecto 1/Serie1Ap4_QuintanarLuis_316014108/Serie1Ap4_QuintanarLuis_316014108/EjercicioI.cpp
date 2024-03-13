#include "EjercicioI.hpp"

void EjercicioI::iniciarI()
{
	i = -1;
	cout << "Dame la cadena que analizaremos lexicamente:" << endl;
	cin >> cadena;
	estado0I();
}
void EjercicioI::estado0I()
{
	i++;
	if ((cadena[i]) == 'a')
		estado1I();
	else
		cout << "Cadena NO valida" << endl;
}
void EjercicioI::estado1I()
{
	i++;
	if ((cadena[i]) == 'b')
		estado2I();
	else
		cout << "Cadena NO valida" << endl;
}
void EjercicioI::estado2I()
{
	i++;
	if ((cadena[i]) == 'a')
		estado3I();
	else
		if ((cadena[i]) == 'b')
			estado4I();
		else
			cout << "Cadena NO valida" << endl;
}
void EjercicioI::estado3I()
{
	i++;
	if ((cadena[i]) == 'a')
		estado3I();
	else
		if ((cadena[i]) == 'b')
			estado4I();
		else
			cout << "Cadena NO valida" << endl;
}
void EjercicioI::estado4I()
{
	i++;
	if ((cadena[i]) == 'a')
		estado5I();
	else
		if ((cadena[i]) == 'b')
			estado6I();
		else
			cout << "Cadena NO valida" << endl;
}
void EjercicioI::estado5I()
{
	i++;
	if ((cadena[i]) == 'a')
		estado5I();
	else
		if ((cadena[i]) == 'b')
			estado6I();
		else
			cout << "Cadena NO valida" << endl;
}
void EjercicioI::estado6I()
{
	i++;
	if ((cadena[i]) == 'a')
		estado7I();
	else
		if ((cadena[i]) == '\0')
			cout << "Cadena Valida" << endl;
		else
			cout << "Cadena NO valida" << endl;
}
void EjercicioI::estado7I()
{
	i++;
	if ((cadena[i]) == 'a')
		estado7I();
	else
		if ((cadena[i]) == '\0')
			cout << "Cadena Valida" << endl;
		else
			cout << "Cadena NO valida" << endl;
}