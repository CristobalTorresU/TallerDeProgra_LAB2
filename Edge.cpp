#include "Edge.h"

/* Constructor
 */
Edge::Edge (int i, int j, int cost) {
	this->i = i;
	this->j = j;
	this->cost = cost;
}

/* Constructor predeterminado
 */
Edge::Edge () {
	this->i = -1;
	this->j = -1;
	this->cost = -1;
}

/* Destructor
 */
Edge::~Edge () {
	// delete
}

bool Edge::contains (int nodo) {
	if (this->i == nodo || this->j == nodo) {
		return true;
	} else {
		return false;
	}
}





