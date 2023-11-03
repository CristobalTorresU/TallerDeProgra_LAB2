#include "Comparator.h"

bool Comparator::operator ()(const Edge* a, const Edge*b) const {
	return a->cost < b->cost;
}
