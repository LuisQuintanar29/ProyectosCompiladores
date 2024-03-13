#ifndef __EJERCICIOB_HPP__
#define __EJERCICIOB_HPP__

#include <iostream>
#include <string>
using namespace std;

class EjercicioB 
{	
	public:
		EjercicioB() = default;
		~EjercicioB() = default;
		void iniciarB();
	private:
		int i = -1;
		string cadena;
		void estado0B();
		void estado1B();
		void estado2B();
		void estado3B();
		void estado4B();
};
#endif