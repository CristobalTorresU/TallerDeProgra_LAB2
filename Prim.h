#include <iostream>
#include <vector>
#include "Edge.h"
#include "MatrizCostos.h"

using namespace std;

class Prim {
	public:
		//Methods
		Prim();
		~Prim();
		void print();
		void resolve();
		int buscarAristaMinima();

		//Atributes
		MatrizCostos *costos;
		vector<int> nodos;
		vector<Edge*> arista;
		vector<Edge*> aristaOut;
		vector<Edge*> aristaDisponibles;
};
