#include "Prim.h"

/*
	* Método: Constructor->Prim
	* Descripción: Crea la clase Prim, sobre la cual se desarrollan los cálculos.
	* Parámetros:
	*	- entrada: Nombre del archivo que posee la matriz que se leerá.
	* Retorna: 
	*	- void
 */
Prim::Prim (string entrada) {
	// Se crea la MatrizCostos y con ella se agregan las aristas.
	this->costos = new MatrizCostos(entrada);
	costos->readFile(entrada);
	aristaDisponibles = new multiset<Edge*, Comparator>[costos->size];
	for (int i = 0 ; i < costos->size ; i++) {
		for (int j = i + 1 ; j < costos->size ; j++) {
			if (costos->matriz[i][j] != 0) {
				Edge *nuevaArista = new Edge(i, j, costos->matriz[i][j]);
				almacenarDisponibles(nuevaArista);
			}
		}
	}
	// Se genera un arreglo que indica si un nodo ya está en las aristas.
	this->costoFinal = 0;
}

/*
	* Método: Destructor->
	* Descripción:
	* Parámetros:
	* Retorna:
 */
Prim::~Prim () {
	/*
	delete[] this->nodos;
	delete[] this->arista;
	delete[] this->aristaOut;
	delete[] this->aristaDisponibles;
	*/
}

/*
	* Método: Otros Metodos->print
	* Descripción: Muestra los valores que contiene el algoritmo Prim,
	* especificamente las aristas del árbol de coste mínimo y el costo final.
	* Parámetros:
	*	- void
	* Retorna:
	*	- void
 */
void Prim::print () {
	auto it2 = arista.begin();
	int i = 0;
	for (; it2 != arista.end() ; it2++) {
		cout << "Arista " << i <<": (" << (*it2)->i << "," << (*it2)->j << ")" << "  Coste: " << (*it2)->cost << endl;
		i += 1;
	}
	//Costo Final
	cout << endl << "Costo final: " << this->costoFinal << endl << endl << endl;
}

/*
	* Método: Otros Métodos->resolve
	* Descripción: Resuelve el algoritmo de Prim, buscando el árbol de coste mínimo
	* que se puede formar, uniendo todos los nodos, mediante un proceso iterativo,
	* en el cual se busca la arista mínima del árbol, hasta que se conecten todos
	* los nodos.
	* Parámetros:
	*	- void
	* Retorna:
	*	- void
 */
void Prim::resolve () {
	//Se ingresa el nodo inicial (ultimo)
	// TODO: Hacer que la eleccion sea aleatoria
	nodos.insert(this->costos->size-1);
	moverAAristasOut(this->costos->size-1);

	while (nodos.size() < this->costos->size) {
		buscarAristaMinima();
	}
}

/*	TODO: SISTEMA PARA QUE NO SE REPITAN QUE SEA FUNCIONAL
 */
/*
	* Método: Otros Métodos->moverAAristaOut
	* Descripción: Mueve Edges desde aristaDisponibles (todas las existentes) a 
	* aristaOut (las que si se pueden alcanzar desde el árbol formado).
	* Parámetros:
	*	- nodo: el nodo nuevo que será ingresado.
	* Retorna:
	*	- void
 */
void Prim::moverAAristasOut (int nodo) {
	for (auto it = aristaDisponibles[nodo].begin() ; it != aristaDisponibles[nodo].end() ; ++it) {
		/*
		if (aristaOut.find((*it)) == aristaOut.end()) {
			aristaOut.insert((*it));
		}
		*/
		aristaOut.insert((*it));
	}
}

/*
	* Método: Otros Métodos->buscarAristaMinima
	* Descripción: Encuentra la arista que tiene el menor valor dentro del arbol
	* Parámetros: Busca la arista de coste mínimo, debido a que el multiset está
	* ordenado por costo, la primera siempre será la de menor costo, pero puede que 
	* ya tenga ambos nodos entre sus aristas, por lo que se eliminan hasta encontrar
	* una que tenga solo un nodo ya almacenado.
	*	- void
	* Retorna:
	*	- void
 */
void Prim::buscarAristaMinima () {
	auto it = aristaOut.begin();

	//Agrega el nodo al vector
	if (!contieneElNodo((*it)->i) || !contieneElNodo((*it)->j)) {
		if (contieneElNodo((*it)->i)) {
			insertarAristaYNodo((*it), (*it)->j);
			moverAAristasOut((*it)->j);
		} else if (contieneElNodo((*it)->j)){
			insertarAristaYNodo((*it), (*it)->i);
			moverAAristasOut((*it)->i);
		}
	}
	// 
	aristaOut.erase(it);
}

/*
	* Método: Otros Métodos->insertarAristaYNodo
	* Descripción: Inserta el nodo y arista ingresados
	* Parámetros:
	*	- nuevaArista: es la arista que que es ingresada en "arista" (árbol ya
	*	formado).
	*	- nodo: el nodo nuevo que se ingresa.
	* Retorna:
	*	- void
*/
void Prim::insertarAristaYNodo (Edge* nuevaArista, int nodo) {
	nodos.insert(nodo);
	arista.insert(nuevaArista);
	costoFinal += nuevaArista->cost;
}

/*
	* Método: Otros Métodos->contieneElNodo
	* Descripción: Verifica si un nodo ingresado se encuentra en el set de nodos.
	* Parámetros:
	*	- n: representa el nodo que se está buscando.
	* Retorna:
	*	- bool: true en caso de que lo contenga, false en caso contrario.
*/
bool Prim::contieneElNodo (int n) {
	if (nodos.find(n) != nodos.end()) {
		return true;
	}
	return false;
}

/*
	* Método: Otros Métodos->almacenarDisponibles
	* Descripción: Agrega la arista ingresada en los dos multiset que representan
	* las aristas con esos nodos.
	* Parámetros:
	*	- nuevaArista: representa la arista que será almacenada en los multiset.
	* Retorna:
	*	- void
*/
void Prim::almacenarDisponibles (Edge* nuevaArista) {
	aristaDisponibles[nuevaArista->i].insert(nuevaArista);
	aristaDisponibles[nuevaArista->j].insert(nuevaArista);
}
