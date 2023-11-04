#ifndef BUSQUEDAPORNODOS_H
#define BUSQUEDAPORNODOS_H
#include <iostream>
#include <set>
#include "Edge.h"

using namespace std;

class BusquedaPorNodos {
	public:
		BusquedaPorNodos(int i, int j);
		bool operator()(const Edge* edge) const;
	private:
		int i;
		int j;
};

#endif
