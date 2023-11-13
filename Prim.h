#include <iostream>
#include <string>
#include <set>
#include "Comparator.h"
#include "MatrizCostos.h"

using namespace std;

/*
	* Clase Prim:
	* uwu
 */
class Prim {
	public:
		// Atributos
		int costoFinal;
		MatrizCostos *costos;
		multiset<int> nodos;
		multiset<Edge*> arista;
		multiset<Edge*, Comparator> aristaOut;

		// Metodos
		// Constructor
		Prim(string entrada);
		
		// Destructor
		~Prim();
		
		// Otros metodos
		void resolve();
		void print();
		void buscarAristaMinima();
		bool contieneElNodo(int n);
		void moverAAristasOut(int nodo);
		void insertarAristaYNodo(Edge* nuevaArista, int nodo);
};
