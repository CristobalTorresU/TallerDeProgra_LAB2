#include "Prim.h"

/*	Constructor
 *	TODO: Que el nombre del archivo sea ingresado por consola
 *	TODO: Verificar que ocurre con la demora cuando se utiliza heap
 */
Prim::Prim () {
	string entrada = "aleatorio.txt";
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
	for (int i = 0 ; i < nodos.size() ; i++) {
		cout << "Nodo " << i << ": " << nodos[i] << endl;
	}
	//Arista
	for (int i = 0 ; i < arista.size() ; i++) {
		cout << "Arista " << i << ": (" << arista[i]->i << "," << arista[i]->j << ")" << "  Coste: " << arista[i]->cost << endl;
	}
	//AristaOut
	for (int i = 0 ; i < aristaOut.size() ; i++) {
		cout << "Arista Out " << i << ": (" << aristaOut[i]->i << "," << aristaOut[i]->j << ")" << "  Coste: " << aristaOut[i]->cost << endl;
	}
	//AristaDisponibles
	for (int i = 0 ; i < aristaDisponibles.size() ; i++) {
		cout << "Arista Disponibles " << i << ": (" << aristaDisponibles[i]->i << "," << aristaDisponibles[i]->j << ")" << "  Coste: " << aristaDisponibles[i]->cost << endl;
	}
	//Costo Final
	cout << "Costo final: " << this->costoFinal << endl << endl << endl;
}

/*	Resuelve el algoritmo de Prim
 */
void Prim::resolve () {
	//Se ingresa el nodo inicial (ultimo)
	this->nodos.push_back(this->costos->size-1);
	pushAristasOut(nodos.front());
	
	while (nodos.size() < this->costos->size) {
		buscarAristaMinima();
		pushAristasOut(nodos.back());
	}
	aristaOut.clear();
	ofstream file;
	file.open("result.txt");
	for (int i = 0 ; i < nodos.size() ; i++) {
		file << nodos[i] << endl;
	}
	file.close();
}

/*	Encuentra la arista que tiene el menor valor dentro del arbol
 *	TODO: Probar usando heap o un quicksort para comparar como afecta al tiempo de ejecucion
 */
void Prim::buscarAristaMinima () {
	int min = aristaOut[0]->cost, pos = 0;
	for (int i = 0 ; i < aristaOut.size() ; i++) {
		if (min > aristaOut[i]->cost && (containsNodo(aristaOut[i]->i) || containsNodo(aristaOut[i]->j))) {
			min = aristaOut[i]->cost;
			pos = i;
		}
		if (min == 1) {
			break;
		}
	}
	Edge* nuevaArista = new Edge(aristaOut[pos]->i, aristaOut[pos]->j, aristaOut[pos]->cost);
	arista.push_back(nuevaArista);
	aristaOut.erase(aristaOut.begin() + pos);
	costoFinal += min;
	//Agrega el nodo al vector
	if (containsNodo(arista.back()->i)) {
		eliminarNodos(arista.back()->j);
		nodos.push_back(arista.back()->j);
		return;
	} else {
		eliminarNodos(arista.back()->i);
		nodos.push_back(arista.back()->i);
		return;
	}
}

/*	Verifica si el vector de nodos contiene uno en especifico
 */
bool Prim::containsNodo (int n) {
	for (int i = 0 ; i < this->nodos.size() ; i++) {
		if (this->nodos[i] == n) {
			return true;
		}
	}
	return false;
}

/*	Ingresar AristaDisponibles en AristaOut
 */
void Prim::pushAristasOut (int nodo) {
	for (int i = 0 ; i < aristaDisponibles.size() ; i++) {
		if (aristaDisponibles[i]->contains(nodo)) {
			Edge* nuevaArista = new Edge(aristaDisponibles[i]->i, aristaDisponibles[i]->j, aristaDisponibles[i]->cost);
			aristaDisponibles.erase(aristaDisponibles.begin() + i);
			aristaOut.push_back(nuevaArista);
			i -= 1;
		}
	}
}

/*	TODO: OPTIMIZABLE, realizar un break, ya que solo elimina 1 arista
 */
void Prim::eliminarNodos (int nodo) {
	for (int i = 0 ; i < this->nodos.size() ; i++) {
		for (int j = 0 ; j < aristaOut.size() ; j++) {
			if ((nodos[i] == aristaOut[j]->i &&
				nodo == aristaOut[j]->j) ||
				(nodos[i] == aristaOut[j]->j &&
				nodo == aristaOut[j]->i)) {
				aristaOut.erase(aristaOut.begin() + j);
				break;
			}
		}
	}
}












