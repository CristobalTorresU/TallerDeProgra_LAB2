#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#define SIZE 300
#define RANDOM 1000

int main () {
	//Crear la matriz
	int **matriz = new int*[SIZE];
	for (int i = 0 ; i < SIZE ; i++) {
		matriz[i] = new int[SIZE];
	}

	//Llenar la matriz
	for (int i = 0 ; i < SIZE ; i++) {
		for (int j = i ; j < SIZE ; j++) {
			if (i == j) {
				matriz[i][j] = 0;
			} else {
				matriz[i][j] = rand() % RANDOM;
				matriz[j][i] = matriz[i][j];
			}
		}
	}

	//Escribir la matriz
	ofstream file;
	file.open("aleatorio.txt");
	for (int i = 0 ; i < SIZE ; i++) {
		for (int j = 0 ; j < SIZE ; j++) {
			file << matriz[i][j] << " ";
		}
		file << endl;
	}
	file.close();
	return 0;
}
