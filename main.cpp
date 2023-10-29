#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Prim.h"

using namespace std;

/*	Algoritmo MST
 */
int main () {
	Prim algoritmo;
	algoritmo.resolve();
	algoritmo.print();
	return 0;
}
