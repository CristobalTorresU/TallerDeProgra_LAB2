#include <iostream>
#include <set>
#include <algorithm>
#include <chrono>
#include "Comparator.h"
#include "MatrizCostos.h"

using namespace std;
using namespace std::chrono;

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
		void insertarAristaYNodo(Edge* nuevaArista, int nodo);

		//Atributes
		int costoFinal;
		MatrizCostos *costos;
		multiset<int> nodos;
		multiset<Edge*, Comparator> arista;
		multiset<Edge*, Comparator> aristaOut;
		multiset<Edge*, Comparator> aristaDisponibles;
};
