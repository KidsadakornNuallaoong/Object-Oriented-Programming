run: 
	@g++ -c main.cpp -o main.o -g
	@g++ -c LinkedList.cpp -o LinkedList.o -g
	@g++ -c ../ChainNode/ChainNode.cpp -o ../ChainNode/ChainNode.o -g
	@g++ main.o LinkedList.o ../ChainNode/ChainNode.o -o LabW4 -g

	@./LabW4

	@rm -f *.o ../ChainNode/ChainNode.o LabW4

all: main.o
	g++ main.o LinkedList.o ../ChainNode/ChainNode.o -o LabW4 -g

main.o: main.cpp LinkedList.cpp ../ChainNode/ChainNode.cpp
	g++ -c main.cpp -o main.o -g
	g++ -c LinkedList.cpp -o LinkedList.o -g
	g++ -c ../ChainNode/ChainNode.cpp -o ../ChainNode/ChainNode.o -g

clean:
	rm -f *.o ../ChainNode/ChainNode.o LabW4
