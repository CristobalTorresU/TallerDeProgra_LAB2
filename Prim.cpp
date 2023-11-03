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
				aristaDisponibles.insert(nuevaArista);
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
	auto it1 = nodos.begin();
	for (; it1 != nodos.end() ; it1++) {
		cout << "Nodo: " << (*it1) << endl;
	}
	//Arista
	auto it2 = arista.begin();
	for (; it2 != arista.end() ; it2++) {
		cout << "Arista: (" << (*it2)->i << "," << (*it2)->j << ")" << "  Coste: " << (*it2)->cost << endl;
	}
	//AristaOut
	auto it3 = aristaOut.begin();
	for (; it3 != aristaOut.end() ; it3++) {
		cout << "AristaOut: (" << (*it3)->i << "," << (*it3)->j << ")" << "  Coste: " << (*it3)->cost << endl;
	}
	//AristaDisponibles
	auto it4 = aristaDisponibles.begin();
	for (; it4 != aristaDisponibles.end() ; it4++) {
		cout << "Arista Disponibles: (" << (*it4)->i << "," << (*it4)->j << ")" << "  Coste: " << (*it4)->cost << endl;
	}
	//Costo Final
	cout << "Costo final: " << this->costoFinal << endl << endl << endl;
}

/*	Resuelve el algoritmo de Prim
 */
void Prim::resolve () {
	//Se ingresa el nodo inicial (ultimo)
	nodos.insert(this->costos->size-1);

	auto it = nodos.begin();

	// TODO: Probablemente un error
	pushAristasOut((*it));

	while (nodos.size() < this->costos->size) {
		buscarAristaMinima();
		it++;
		pushAristasOut((*it));
	}
	aristaOut.clear();
	
	/*
	ofstream file;
	file.open("result.txt");
	for (int i = 0 ; i < nodos.size() ; i++) {
		file << nodos[i] << endl;
	}
	file.close();
	*/
}

/*	Encuentra la arista que tiene el menor valor dentro del arbol
 *	TODO: Probar usando heap o un quicksort para comparar como afecta al tiempo de ejecucion
 *	TODO: Probar que ocurre si no se eliminan las aristas inutiles
 *	TODO: Probar cuando se elimina todo lo que busca, ya que aristaOut ya tienen aristas que sirven
 *	TODO: Implementar con find
 */
void Prim::buscarAristaMinima () {
	auto it = aristaOut.begin();
	Edge* nuevaArista = new Edge((*it)->i, (*it)->j, (*it)->cost);
	arista.insert(nuevaArista);
	costoFinal += nuevaArista->cost;
	aristaOut.erase(it);

	//Agrega el nodo al vector
	if (containsNodo(nuevaArista->i)) {
		eliminarNodos(nuevaArista->j);
		nodos.insert(nuevaArista->j);
		return;
	} else {
		eliminarNodos(nuevaArista->i);
		nodos.insert(nuevaArista->i);
		return;
	}
}

/*	Verifica si el vector de nodos contiene uno en especifico
 */
bool Prim::containsNodo (int n) {
	auto it = nodos.begin();
	for (; it != nodos.end() ; it++) {
		if ((*it) == n) {
			return true;
		}
	}
	return false;
}

/*	Ingresar AristaDisponibles en AristaOut
 *	TODO: Implementar con find
 *	TODO: Retroceder el it
 *	TODO: Aplicar de forma inteligente, siempre estan ordenados con el menor primero
 */
void Prim::pushAristasOut (int nodo) {
	auto it = aristaDisponibles.begin();
	for (; it != aristaDisponibles.end() ; it++) {
		if ((*it)->contains(nodo)) {
			cout << "owo" << endl;
			Edge* nuevaArista = new Edge((*it)->i, (*it)->j, (*it)->cost);
			aristaDisponibles.erase(it);
			aristaOut.insert(nuevaArista);
			it--;
			cout << "owo" << endl;
		}
	}

	auto it = aristaDisponibles.find();
}

/*	Elimina todas las aristas que ya no se utilizaran en la solucion
 *	TODO: Adaptar para utilizarlo con iteradores
 *	TODO: Poner nombres significativos para los iteradores
 *	TODO: Implementar con find
 *	TODO: Buscar de forma inteligente, siempre estan ordenados con el menor primero
 */
void Prim::eliminarNodos (int nodo) {
	auto it1 = nodos.begin();
	for (; it1 != nodos.end() ; it1++) {
		auto it2 = aristaOut.begin();
		for (; it2 != aristaOut.end() ; it2++) {
			if (((*it1) == (*it2)->i &&
				nodo == (*it2)->j) ||
				((*it1) == (*it2)->j &&
				nodo == (*it2)->i)) {
				aristaOut.erase(it2);
				break;
			}
		}
	}
}












