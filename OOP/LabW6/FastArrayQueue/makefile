run:
	@g++ -c main.cpp -o main.o
	@g++ -c FastArrayQueue.cpp -o FastArrayQueue.o
	@g++ main.o FastArrayQueue.o -o FastArrayQueue

	@./FastArrayQueue

	@rm -f *.o FastArrayQueue

all: main.o FastArrayQueue.o
	g++ main.o FastArrayQueue.o -o FastArrayQueue -g

main.o: main.cpp
	g++ -c main.cpp -o main.o

FastArrayQueue.o: FastArrayQueue.cpp
	g++ -c FastArrayQueue.cpp -o FastArrayQueue.o

clean:
	rm -f *.o FastArrayQueue