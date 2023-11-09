#include "Prim.h"

/*	Constructor
 */
Prim::Prim (string entrada) {
	this->costos = new MatrizCostos(entrada);
	costos->readFile(entrada);
	for (int i = 0 ; i < costos->size ; i++) {
		for (int j = i + 1 ; j < costos->size ; j++) {
			if (costos->matriz[i][j] != 0) {
				Edge *nuevaArista = new Edge(i, j, costos->matriz[i][j]);
				aristaDisponibles.insert(nuevaArista);
			}
		}
	}
	// NUEVO
	nodos = new bool[costos->size];
	for (int i = 0 ; i < costos->size ; i++) {
		nodos[i] = false;
	}
	Nnodos = 0;
	// NUEVO
	this->costoFinal = 0;
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
	/*
	auto it1 = nodos.begin();
	for (; it1 != nodos.end() ; it1++) {
		cout << "Nodo: " << (*it1) << endl;
	}
	*/
	//Arista
	auto it2 = arista.begin();
	for (; it2 != arista.end() ; it2++) {
		cout << "Arista: (" << (*it2)->i << "," << (*it2)->j << ")" << "  Coste: " << (*it2)->cost << endl;
	}
	//Costo Final
	cout << endl << "Costo final: " << this->costoFinal << endl << endl << endl;
}

/*	Resuelve el algoritmo de Prim
 */
void Prim::resolve () {
	//Se ingresa el nodo inicial (ultimo)
	//nodos.insert(this->costos->size-1);
	nodos[this->costos->size-1] = true;
	Nnodos += 1;

	pushAristasOut(this->costos->size-1);

	while (Nnodos < this->costos->size) {
		buscarAristaMinima();
	}

	aristaOut.clear();
}

/*	Encuentra la arista que tiene el menor valor dentro del arbol
 */
void Prim::buscarAristaMinima () {
	auto it = aristaOut.begin();

	//Agrega el nodo al vector
	if (!containsNodo((*it)->i) || !containsNodo((*it)->j)) {
		if (containsNodo((*it)->i)) {
			insertarAristaYNodo((*it), (*it)->j);
			pushAristasOut((*it)->j);
		} else if (containsNodo((*it)->j)){
			insertarAristaYNodo((*it), (*it)->i);
			pushAristasOut((*it)->i);
		}
	}

	aristaOut.erase(it);
}

/*	Inserta el nodo y arista ingresados
 */
void Prim::insertarAristaYNodo (Edge* nuevaArista, int nodo) {
	nodos[nodo] = true;
	Nnodos += 1;
	arista.insert(nuevaArista);
	costoFinal += nuevaArista->cost;
}

/*	Verifica si el vector de nodos contiene uno en especifico
 */
bool Prim::containsNodo (int n) {
	/*
	auto it = nodos.find(n);
	if (it != nodos.end()) {
		return true;
	}

	return false;
	*/
	return nodos[n];
}

/*	Ingresar AristaDisponibles en AristaOut
 */
void Prim::pushAristasOut (int nodo) {
	for (auto it = aristaDisponibles.begin(); it != aristaDisponibles.end() ;) {
		if ((*it)->contains(nodo)) {
			aristaOut.insert((*it));
			it = aristaDisponibles.erase(it);
		} else {
			++it;
		}
	}
}








