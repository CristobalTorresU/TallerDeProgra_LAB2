#include "Edge.h"

/*
	* Método: Otros Métodos->Constructor
	* Descripción: Crea la clase Edge, que representa una arista, con un nodo i de
	* incio, un nodo j de llegada y su costo asociado.
	* Parámetros:
	*	- i: nodo de inicio.
	*	- j: nodo de llegada.
	*	- costo: costo asociado a ir del nodo i al nodo j.
	* Retorna:
	*	- void
*/
Edge::Edge (int i, int j, int cost) {
	this->i = i;
	this->j = j;
	this->cost = cost;
}

/*
	* Método: Otros Métodos->Destructor
	* Descripción:
	* Parámetros:
	* Retorna:
*/
Edge::~Edge () {
}

/*
	* Método: Otros Métodos->contains
	* Descripción: Verifica si el Edge contiene el nodo ingresado.
	* Parámetros:
	* Retorna:
*/
bool Edge::contains (int nodo) {
	if (this->i == nodo || this->j == nodo) {
		return true;
	} else {
		return false;
	}
}
