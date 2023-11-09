#include <set>
#include "Edge.h"

int main () {
	/*
	multiset<Edge*> s;
	int opcion;
	while (true) {
		cout << "Elija una alternativa:" << endl;
		cout << "0. Agregar una arista" << endl;
		cout << "1. Mostrar aristas" << endl;
		cout << "2. Buscar que aristas contienen cierto nodo" << endl;
		cout << "3. Salir del test" << endl;
		cin >> opcion;
		cout << endl;
		switch (opcion) {
			case 0:
				// Creacion de aristas (Edges)
				string i;
				string j;
				string cost;
				cout << "Ingrese el valor de i: ";
				cin >> i;
				cout << endl;
				cout << "Ingrese el valor de j: ";
				cin >> j;
				cout << endl;
				cout << "Ingrese el valor de cost: ";
				cin >> cost;
				cout << endl;
				// Se inserta el Edge en un multiset
				s.insert(new Edge(stoi(i),stoi(j),stoi(cost)));
				break;
			case 1:
				cout << "Aristas ingresadas:" << endl;
				for (auto it = s.begin() ; it != s.end() ; ++it) {
					cout << "(" << (*it)->i << "," << (*it)->j << ") Costo = ";
					cout << (*it)->cost << endl;
				}
				break;
			case 2:
				// Verificamos cuales son los Edges que contienen un nodo ingresado.
				string nodo;
				cout << "Ingrese el nodo que se desea buscar: ";
				cin >> nodo;
				cout << endl;
				cout << "Contienen el nodo " << nodo << ":" << endl;
				for (auto it = s.begin() ; it != s.end() ; ++it) {
					if (Edge::contains(stoi(nodo)) == true) {
						cout << "(" << (*it)->i << "," << (*it)->j;
						cout << ") Costo = " << (*it)->cost << endl;
					}
				}
				break;
			case 3:
				return 0;
				break;
		}
	}\
	*/
}
