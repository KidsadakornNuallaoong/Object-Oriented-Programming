run:
	@g++ -c main.cpp -o main.o
	@g++ -c FastLinkedQueue.cpp -o FastLinkedQueue.o
	@g++ -c ../ChainNode/ChainNode.cpp -o ../ChainNode/ChainNode.o
	@g++ main.o FastLinkedQueue.o ../ChainNode/ChainNode.cpp -o FastLinkedQueue

	@./FastLinkedQueue

	@rm -f *.o FastLinkedQueue ../ChainNode/ChainNode.o

all: main.o FastLinkedQueue.o ../ChainNode/ChainNode.o
	g++ main.o FastLinkedQueue.o -o FastLinkedQueue -g

main.o: main.cpp
	g++ -c main.cpp -o main.o

FastLinkedQueue.o: FastLinkedQueue.cpp
	g++ -c FastLinkedQueue.cpp -o FastLinkedQueue.o

../ChainNode/ChainNode.o: g++ -c ../ChainNode/ChainNode.cpp
	g++ -c ../ChainNode/ChainNode.cpp -o ../ChainNode/ChainNode.o

clean:
	rm -f *.o FastLinkedQueue ../ChainNode/ChainNode.o