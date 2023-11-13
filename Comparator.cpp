#include "Comparator.h"

/*
	* Método: Otros Métodos->
	* Descripción:
	* Parámetros:
	* Retorna:
 */
bool Comparator::operator ()(const Edge* a, const Edge*b) const {
	return a->cost < b->cost;
}
