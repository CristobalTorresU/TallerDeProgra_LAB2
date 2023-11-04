#ifndef EDGE_H
#define EDGE_H
#include <iostream>

/* Clase que representa cada arista del algoritmo
 */
class Edge {
	public:
		//Methods
		Edge(int i, int j, int cost);
		Edge();
		~Edge();
		bool contains(int nodo);

		//Atributes
		int i;
		int j;
		int cost;
};

#endif
