FLAGS=-g

all: generador test_MatrizCostos test_Edge main

main: Prim.o MatrizCostos.o Edge.o Comparator.o main.cpp
	g++ ${FLAGS} Prim.o MatrizCostos.o Edge.o Comparator.o main.cpp -o MAIN
generador: generador.cpp
	g++ ${FLAGS} generador.cpp -o GENERADOR
test_MatrizCostos: MatrizCostos.o test_MatrizCostos.cpp
	g++ ${FLAGS} MatrizCostos.o test_MatrizCostos.cpp -o test_MatrizCostos
test_Edge: Edge.o test_Edge.cpp
	g++ ${FLAGS} Edge.o test_Edge.cpp -o test_Edge
Prim.o: Prim.cpp Prim.h
	g++ ${FLAGS} -c Prim.cpp
MatrizCostos.o: MatrizCostos.cpp MatrizCostos.h
	g++ ${FLAGS} -c MatrizCostos.cpp
Edge.o: Edge.cpp Edge.h
	g++ ${FLAGS} -c Edge.cpp
Comparator.o: Comparator.cpp Comparator.h
	g++ ${FLAGS} -c Comparator.cpp
clean:
	rm -f *.o MAIN GENERADOR test_MatrizCostos test_Edge
