#ifndef COMPARATOR_H
#define COMPARATOR_H
#include <iostream>
#include <set>
#include "Edge.h"

using namespace std;

class Comparator {
	public:
		//Methods
		bool operator ()(const Edge* a, const Edge*b) const;
		//Atributes
};

#endif
