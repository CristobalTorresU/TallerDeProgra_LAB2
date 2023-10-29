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
		void insertValue(int i, int j, int value);
		void print();
	
		//Atributes
		int size;
		int **matriz;
};
