all:	main
main: main.o Package.o OvernightPackage.o TwoDayPackage.o	
	g++ main.o Package.o OvernightPackage.o TwoDayPackage.o -o main
main.o: main.cpp
	g++ -c main.cpp
Package.o: Package.cpp
	g++ -c Package.cpp
OvernightPackage.o: OvernightPackage.cpp
	g++ -c OvernightPackage.cpp
TwoDayPackage.o: TwoDayPackage.cpp
	g++ -c TwoDayPackage.cpp
clean:
	rm -f *.o main
