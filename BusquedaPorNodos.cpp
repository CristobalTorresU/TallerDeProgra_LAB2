#include "BusquedaPorNodos.h"

BusquedaPorNodos::BusquedaPorNodos (int i, int j) : i(i), j(j) {}

bool BusquedaPorNodos::operator()(const Edge* edge) const {
	return (edge->i == i) && (edge->j == j);
}
