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
int main () {
	// Ingresar un archivo y determina si existe
	string entrada;
	cout << "Ingrese el nombre del archivo: ";
	cin >> entrada;
	cout << endl;
	ifstream file(entrada);
	// En caso de que el archivo no exista, se cierra y se termina la ejecucion
	if (!file.is_open()) {
		cout << "El archivo ingresado no existe." << endl;
		file.close();
		return 0;
	}
	file.close();

	Prim algoritmo(entrada);
	// Inicio del timer
	auto start = high_resolution_clock::now();
	// Se ejecuta el algoritmo
	algoritmo.resolve();
	// Final del timer
	auto stop = high_resolution_clock::now();
	// Se muestran los nodos y aristas resultantes
	algoritmo.print();

	// Se muestra el tiempo final en milisegundos
	auto duration = duration_cast<milliseconds>(stop - start);
	cout << "La función toma un tiempo de: ";
	cout << duration.count() << " milisegundos." << endl;
	return 0;
}
