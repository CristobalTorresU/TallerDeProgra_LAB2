#include "Prim.h"

/*	Constructor
 */
Prim::Prim () {
	string entrada = "entrada3.txt";
	this->costos = new MatrizCostos(entrada);
	costos->readFile(entrada);
	for (int i = 0 ; i < costos->size ; i++) {
		for (int j = i + 1 ; j < costos->size ; j++) {
			if (costos->matriz[i][j] != 0) {
				Edge *nuevaArista = new Edge(i, j, costos->matriz[i][j]);
				aristaDisponibles.push_back(nuevaArista);
			}
		}
	}
}

/* Destructor	
 */
Prim::~Prim () {
	/*
	delete[] this->nodos;
	delete[] this->arista;
	delete[] this->aristaOut;
	delete[] this->aristaDisponibles;
	*/
}

/*	Muestra los valores que contiene el algoritmo Prim
 */
void Prim::print () {
	//Nodos
	for (int i = 0 ; i < nodos.size() ; i++) {
		cout << "Nodo " << i << ": " << nodos[i] << endl;
	}
	//Arista
	for (int i = 0 ; i < arista.size() ; i++) {
		cout << "Arista " << i << ": (" << arista[i]->i << "," << arista[i]->j << ")" << "  Coste: " << endl;
	}
	//AristaOut
	for (int i = 0 ; i < aristaOut.size() ; i++) {
		cout << "Arista " << i << ": (" << aristaOut[i]->i << "," << aristaOut[i]->j << ")" << "  Coste: " << aristaOut[i]->cost << endl;
	}
	//AristaDisponibles
	for (int i = 0 ; i < aristaDisponibles.size() ; i++) {
		cout << "Arista " << i << ": (" << aristaDisponibles[i]->i << "," << aristaDisponibles[i]->j << ")" << "  Coste: " << aristaDisponibles[i]->cost << endl;
	}

}

/*	Resuelve el algoritmo de Prim
 *	TODO: RESOLVER LA CUESTION XDDDDD
 */
void Prim::resolve () {
	while () {}
}

/*	Encuentra la arista que tiene el menor valor dentro del arbol
 *	TODO: Probar usando heap o un quicksort para comparar como afecta al tiempo de ejecucion
 */
int Prim::buscarAristaMinima () {
	int min = 0, pos = 0;
	for (int i = 0 ; i < aristaOut.size() ; i++) {
		if (min > aristaOut[i]->cost) {
			min = aristaOut[i]->cost;
		}
	}
	return pos;
}







