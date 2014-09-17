all: main
main: main.o Trip.o
	g++ main.o Trip.o -o main
main.o: main.cpp
	g++ -c main.cpp
Trip.o: Trip.cpp
	g++ -c Trip.cpp
clean:
	rm -f *.o main
