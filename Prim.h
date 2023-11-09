#include <iostream>
#include <string>
#include <set>
#include "Comparator.h"
#include "MatrizCostos.h"

using namespace std;

class Prim {
	public:
		//Methods
		Prim(string entrada);
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
		//multiset<int> nodos;
		bool* nodos;
		int Nnodos;
		multiset<Edge*> arista;
		multiset<Edge*, Comparator> aristaOut;
		multiset<Edge*, Comparator> aristaDisponibles;
};
