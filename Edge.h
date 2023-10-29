#include <iostream>

/* Clase que representa cada arista del algoritmo
 */
class Edge {
	public:
		//Methods
		Edge(int i, int j, int cost);
		Edge();
		~Edge();

		//Atributes
		int i;
		int j;
		int cost;
};