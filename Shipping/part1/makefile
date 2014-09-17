all:	main
main: main.o BankAccount.o BoatLoan.o IslandLoan.o
	g++ main.o BankAccount.o BoatLoan.o IslandLoan.o -o main
main.o: main.cpp
	g++ -c main.cpp
BankAccount.o: BankAccount.cpp
	g++ -c BankAccount.cpp
BoatLoan.o: BoatLoan.cpp
	g++ -c BoatLoan.cpp
IslandLoan.o: IslandLoan.cpp
	g++ -c IslandLoan.cpp
clean:
	rm -f *.o main
