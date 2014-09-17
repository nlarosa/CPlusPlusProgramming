all: main
main: main.o CardDeck.o BlackJack.o
	g++ main.o CardDeck.o BlackJack.o -o main
main.o: main.cpp
	g++ -c main.cpp
CardDeck.o: CardDeck.cpp
	g++ -c CardDeck.cpp
BlackJack.o: BlackJack.cpp
	g++ -c BlackJack.cpp
clean:
	rm -f *.o main
