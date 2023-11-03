#include <iostream>
#include <set>
#include "Edge.h"

using namespace std;

class Node {
	public:
		int key;
		int value;
		Node() {
			key = 0;
			value = 0;
		}
		~Node(){}
};

class Comparator {
	public:
		bool operator ()(const Edge* a, const Edge* b) const {
			return a->cost < b->cost;
		}
};

int main () {
	set<Edge *, Comparator> s;
	Edge* E1 = new Edge(0,1,15);
	Edge* E2 = new Edge(0,2,23);
	Edge* E3 = new Edge(0,3,35);
	Edge* E4 = new Edge(1,2,4);
	Edge* E5 = new Edge(1,3,22);
	Edge* E6 = new Edge(2,3,16);

	s.insert(E1);
	s.insert(E2);
	s.insert(E3);
	s.insert(E4);
	s.insert(E5);
	s.insert(E6);

	auto it = s.begin();
	for (; it != s.end() ; it++) {
		cout << (*it)->cost << ": (" << (*it)->i << "," << (*it)->j << ")" << endl;
	}
	return 0;
}
