main: main.o complex.o sort.o
	g++ -o program main.o complex.o sort.o

complex.o: complex.h complex.cpp
	g++ -c complex.cpp

sort.o: sort.h sort.cpp
	g++ -c sort.cpp

run:
	./program

clean:
	rm -f *.o program