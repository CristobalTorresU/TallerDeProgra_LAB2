#include <iostream>

#include <vector>
#include <list>

#include <set>
#include <string>
// ref: https://en.cppreference.com/w/cpp/container/vector

using namespace std;

class Node {
    public:
    int x;
    int y;
    Node(){
        x=0;
        y=0;
    }
    ~Node(){}
};


int main() {
    // vector es una clase templatizada
    vector<int> x; /// llama al constructor vacio

    cout << "tamaño del vector: " << x.size() << endl;

    for (int i = 0; i < 100; i++) {
        x.push_back(i); // push_back inserta un elemento al final
        cout << "tamaño:"<<x.size() << " capacidad: " << x.capacity() << endl;
    }

    for (int i = 0; i < x.size(); i++) {
        cout << x[i] << " " << endl; /// el acceso a cada elemento es por []
    }

    vector<Node *> y;
    Node *n = new Node();

    y.push_back(n);
    cout << "x:" << y[0]->x << " y:" << y[0]->y << endl;

    // iteradores: for automatico sin conocer indices
    for(auto a : x){
        cout << "Valor: " << a << endl; // warning: no sabemos donde estamos
    }

    // iteradores de rango
    vector<int>::iterator it; // iterador de vector de enteros
    /* Un iterador abstrae el concepto de puntero a un elemento del contenedor.
    la operacion it++ se reescibio en la clase iterator para que se mueva al 
    siguiente elemento del contenedor.
    la operacion *it se busca el valor al cual esta referenciado este iterador.
    */
    for(it = x.begin(); it != x.end(); it++){
        cout << "Valor: " << *it << endl;
    }


    // veamos lo mismo con listas
    list<int> z;
    for (int i = 0; i < 100; i++) {
        z.push_back(100-i); // push_back inserta un elemento al final
        cout << "tamaño:"<<z.size() << " capacidad: " << z.max_size() << endl;
    }

    for(auto itList = z.begin(); itList != z.end(); itList++){
        cout << "Valor: " << *itList << endl;
    }

// desde las slides
multiset<string> cities {
"Braunschweig", "Hanover", "Frankfurt", "New York",
"Chicago", "Toronto", "Paris", "Frankfurt"
};
for (const auto& elem : cities) {
cout << elem << " ";
}
cout << endl;
cities.insert( {"London", "Munich", "Hanover", "Braunschweig"} );
for (const auto& elem : cities) {
cout << elem << " ";
}
cout << endl;

}