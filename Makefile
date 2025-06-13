test:
	clang++ -Wall -g ./Game/main.cpp ./Game/Card/card.cpp ./Game/Deck/deck.cpp ./Game/Room/room.cpp -o test

build:
	clang++ -Wall ./Game/main.cpp -c
	clang++ -Wall ./Game/Card/card.cpp -c
	clang++ -Wall ./Game/Deck/deck.cpp -c
	clang++ -Wall ./Game/Player/player.cpp -c
	clang++ -Wall ./Game/Room/room.cpp -c
	clang++ -g main.o deck.o room.o card.o player.o -o scoundrel
	rm main.o deck.o room.o card.o player.o

clean:
	# rm -rf test test.dSYM
	rm main.o deck.o room.o
