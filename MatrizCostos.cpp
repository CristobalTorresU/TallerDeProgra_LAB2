#include "MatrizCostos.h"

MatrizCostos::MatrizCostos (string matrizEntrada) {
	ifstream file(matrizEntrada);
	string line;
	int size = 0;
	while (getline(file, line)) {
		size += 1;
	}
	file.close();

	this->size = size;
	this->matriz = new int*[size];
	for (int i = 0 ; i < size ; i++) {
		this->matriz[i] = new int[size];
		for (int j = 0 ; j < size ; j++) {
			this->matriz[i][j] = 0;
		}
	}
}

// TODO: Verificar que el archivo exista, en caso de que no, 
// finalizar la ejecucion
void MatrizCostos::readFile(string matrizEntrada) {
	ifstream file(matrizEntrada);
	string line, value;
	int countI = 0, countJ = 0;

	while (getline(file, line)) {
		stringstream charStream;
		charStream << line;
		stringstream part(line);
		while (getline(part, value, ' ')) {
			insertValue(countI, countJ, stoi(value));
			countJ += 1;
		}
		countJ = 0;
		countI += 1;
	}

	file.close();
	cout << "Cantidad de nodos: " << countI << endl << endl;
}

MatrizCostos::~MatrizCostos () {
	delete[] this->matriz;
}

void MatrizCostos::insertValue (int i, int j, int value) {
	this->matriz[i][j] = value;
}

void MatrizCostos::print () {
	cout << "Matriz de Costos:" << endl;
	for (int i = 0 ; i < this->size ; i++) {
		for (int j = 0 ; j < size ; j++) {
			cout << this->matriz[i][j] << " ";
		}
		cout << endl;
	}
}
