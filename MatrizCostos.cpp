#include "MatrizCostos.h"

/* Crea una matriz del tamaño de la cantidad de líneas que tenga el archivo
 */
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
	}
}

/*	Agrega los valores desde el archivo de entrada a la clase MatrizCostos
 */
void MatrizCostos::readFile(string matrizEntrada) {
	ifstream file(matrizEntrada);
	string line, value;
	int countI = 0, countJ = 0;

	while (getline(file, line)) {
		stringstream charStream;
		charStream << line;
		stringstream part(line);
		while (getline(part, value, ' ')) {
			matriz[countI][countJ] = stoi(value);
			countJ += 1;
		}
		countJ = 0;
		countI += 1;
	}

	file.close();
	cout << "Cantidad de nodos: " << countI << endl << endl;
}

/*
 */
MatrizCostos::~MatrizCostos () {
	delete[] this->matriz;
}

void MatrizCostos::print() {
	for (int i = 0 ; i < this->size ; i++) {
		for (int j = 0 ; j < this->size ; j++) {
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
}






