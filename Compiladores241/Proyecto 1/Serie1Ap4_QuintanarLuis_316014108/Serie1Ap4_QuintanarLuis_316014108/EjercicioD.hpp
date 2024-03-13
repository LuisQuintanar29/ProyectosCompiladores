#ifndef __EJERCICIOD_HPP__
#define __EJERCICIOD_HPP__

#include <iostream>
#include <string>
using namespace std;

class EjercicioD
{
public:
	EjercicioD() = default;
	~EjercicioD() = default;
	void iniciarD();
private:
	string cadena;
	int i = -1;
	void estado0D();
	void estado1D();
	void estado2D();
	void estado3D();
	void estado4D();
	void estado5D();
	void estado6D();
};
#endif