FLAGS=-g

all: generador main

main: Prim.o MatrizCostos.o Edge.o Comparator.o BusquedaPorNodos.o main.cpp
	g++ ${FLAGS} Prim.o MatrizCostos.o Edge.o Comparator.o BusquedaPorNodos.o main.cpp -o MAIN
generador: generador.cpp
	g++ ${FLAGS} generador.cpp -o GENERADOR
Prim.o: Prim.cpp Prim.h
	g++ ${FLAGS} -c Prim.cpp
MatrizCostos.o: MatrizCostos.cpp MatrizCostos.h
	g++ ${FLAGS} -c MatrizCostos.cpp
Edge.o: Edge.cpp Edge.h
	g++ ${FLAGS} -c Edge.cpp
Comparator.o: Comparator.cpp Comparator.h
	g++ ${FLAGS} -c Comparator.cpp
BusquedaPorNodos.o: BusquedaPorNodos.cpp BusquedaPorNodos.h
	g++ ${FLAGS} -c BusquedaPorNodos.cpp
clean:
	rm -f *.o MAIN GENERADOR
