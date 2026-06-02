test:
	g++ -Wall -g ./Game/main.cpp ./Game/Card/card.cpp ./Game/Deck/deck.cpp ./Game/Room/room.cpp ./Game/Player/player.cpp -o test

build:
	g++ -Wall ./Game/main.cpp -c
	g++ -Wall ./Game/Card/card.cpp -c
	g++ -Wall ./Game/Deck/deck.cpp -c
	g++ -Wall ./Game/Player/player.cpp -c
	g++ -Wall ./Game/Room/room.cpp -c
	g++ -g main.o deck.o room.o card.o player.o -o scoundrel
	rm main.o deck.o room.o card.o player.o

clean:
	# rm -rf test test.dSYM
	rm main.o deck.o room.o
