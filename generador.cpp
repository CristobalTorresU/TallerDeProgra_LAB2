// Para usar el generador ./generador <tamaño matix>
#include <iostream>
#include <fstream>
#include <cstdlib>  // for atoi and rand
#include <ctime>    // for time

using namespace std;

int main(int argc, char *argv[]) {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    if(argc != 2) {
        cerr << "Usage: " << argv[0] << " size" << endl;
        return 1;
    }

    int n = atoi(argv[1]); // Convert the argument to an integer
    int **c = new int*[n];
    ofstream archivo("costos.txt");
    
    if(!archivo) {
        cerr << "Cannot open file." << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        c[i] = new int[n];
    }

    for(int i = 0; i < n; i++) {
        c[i][i] = 0;
        for(int j=i+1; j < n; j++) {
            c[i][j] = rand() % 1000 + 1;
            c[j][i] = c[i][j];
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j=0; j < n; j++) {
            archivo << c[i][j] << " ";
        }
        archivo << endl;
    }

    // Free the allocated memory
    for (int i = 0; i < n; i++) {
        delete[] c[i];
    }
    delete[] c;

    archivo.close();
    return 0;
}
