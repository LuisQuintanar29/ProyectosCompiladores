#ifndef __EJERCICIOI_HPP__
#define __EJERCICIOI_HPP__

#include <iostream>
#include <string>
using namespace std;

class EjercicioI
{
public:
	EjercicioI() = default;
	~EjercicioI() = default;
	void iniciarI();
private:
	string cadena;
	int i = -1;
	void estado0I();
	void estado1I();
	void estado2I();
	void estado3I();
	void estado4I();
	void estado5I();
	void estado6I();
	void estado7I();
};
#endif