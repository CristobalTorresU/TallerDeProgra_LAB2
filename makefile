FLAGS=-g

all: test_MatrizCostos test_Edge test_Prim main

main: Prim.o MatrizCostos.o Edge.o Comparator.o main.cpp
	g++ ${FLAGS} Prim.o MatrizCostos.o Edge.o Comparator.o main.cpp -o MAIN
test_MatrizCostos: MatrizCostos.o test_MatrizCostos.cpp
	g++ ${FLAGS} MatrizCostos.o test_MatrizCostos.cpp -o test_MatrizCostos
test_Edge: Edge.o test_Edge.cpp
	g++ ${FLAGS} Edge.o test_Edge.cpp -o test_Edge
test_Prim: MatrizCostos.o Edge.o Prim.o Comparator.o test_Prim.cpp
	g++ ${FLAGS} MatrizCostos.o Edge.o Prim.o Comparator.o test_Prim.cpp -o test_Prim
Prim.o: Prim.cpp Prim.h
	g++ ${FLAGS} -c Prim.cpp
MatrizCostos.o: MatrizCostos.cpp MatrizCostos.h
	g++ ${FLAGS} -c MatrizCostos.cpp
Edge.o: Edge.cpp Edge.h
	g++ ${FLAGS} -c Edge.cpp
Comparator.o: Comparator.cpp Comparator.h
	g++ ${FLAGS} -c Comparator.cpp
clean:
	rm -f *.o MAIN test_MatrizCostos test_Edge test_Prim resultado.txt
