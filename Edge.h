#ifndef EDGE_H
#define EDGE_H
#include <iostream>

using namespace std;

/* 
	* Clase Edge:
	* Clase que representa cada arista del algoritmo
	*
 */
class Edge {
	public:
		// Atributos
		int i;
		int j;
		int cost;

		// Metodos

		// Constructor
		Edge(int i, int j, int cost);
		
		// Destructor
		~Edge();
		
		// Otros metodos
		bool contains(int nodo);
};

#endif /* EDGE_H */
