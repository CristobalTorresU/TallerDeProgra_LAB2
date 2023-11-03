#include <iostream>
#include <set>
#include "Comparator.h"
#include "MatrizCostos.h"

using namespace std;

class Prim {
	public:
		//Methods
		Prim();
		~Prim();
		void print();
		void resolve();
		void buscarAristaMinima();
		bool containsNodo(int n);
		void pushAristasOut(int nodo);
		void eliminarNodos(int nodo);

		//Atributes
		int costoFinal;
		MatrizCostos *costos;
		set<int> nodos;
		multiset<Edge*, Comparator> arista;
		multiset<Edge*, Comparator> aristaOut;
		multiset<Edge*, Comparator> aristaDisponibles;
};
