#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <sstream>
#include "Prim.h"

using namespace std;
using namespace std::chrono;

/*	Algoritmo MST
 */
int main (int argc, char* argv[]) {
	// Ingresar un archivo y determina si existe
	string entrada = argv[1];
	cout << endl;
	ifstream file(entrada);
	// En caso de que el archivo no exista, se cierra y se termina la ejecucion
	if (!file.is_open()) {
		cout << "El archivo ingresado no existe." << endl;
		file.close();
	} else {
		file.close();
		Prim algoritmo(entrada);
		// Inicio del timer
		auto start = high_resolution_clock::now();
		// Se ejecuta el algoritmo
		algoritmo.resolve();
		// Final del timer
		auto stop = high_resolution_clock::now();
		// Se muestran los nodos y aristas resultantes
		ofstream archivo("resultado.txt");
		for (auto it = algoritmo.arista.begin() ; it != algoritmo.arista.end() ; ++it) {
			archivo << "(" << (*it)->i << "," << (*it)->j << ") Costo = " << (*it)->cost << endl;
		}
		archivo << "Costo Total: " << algoritmo.costoFinal << endl;
		archivo.close();
		cout << "Costo Minimo: " << algoritmo.costoFinal << endl;
		// Se muestra el tiempo final en milisegundos
		auto duration = duration_cast<microseconds>(stop - start);
		cout << "La función toma un tiempo de: ";
		cout << duration.count() << " microsegundos." << endl;
	}
	return 0;
}
