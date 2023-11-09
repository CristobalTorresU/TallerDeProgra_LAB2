#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class MatrizCostos {
	public:
		//Methods
		MatrizCostos(string matrizEntrada);
		~MatrizCostos();
		void readFile(string matrizEntrada);
		void print();
	
		//Atributes
		int size;
		int **matriz;
};
