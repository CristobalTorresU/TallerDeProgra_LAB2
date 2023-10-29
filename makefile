FLAGS=-g

main: Prim.o MatrizCostos.o Edge.o main.cpp
	g++ ${FLAGS} Prim.o MatrizCostos.o Edge.o main.cpp -o MAIN
Prim.o: Prim.cpp Prim.h
	g++ ${FLAGS} -c Prim.cpp
MatrizCostos.o: MatrizCostos.cpp MatrizCostos.h
	g++ ${FLAGS} -c MatrizCostos.cpp
Edge.o: Edge.cpp Edge.h
	g++ ${FLAGS} -c Edge.cpp
clean:
	rm -f *.o MAIN
