#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

/*
	* Clase MatrizCostos:
	* uwu
 */
class MatrizCostos {
	public:
		// Atributos
		int size;
		int **matriz;

		// Metodos
		// Constructor
		MatrizCostos(string matrizEntrada);
		// Destructor
		~MatrizCostos();

		// OtrosMetodos
		void readFile(string matrizEntrada);
		void print();
};
