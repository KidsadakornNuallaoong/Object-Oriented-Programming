run: 
	@g++ -c main.cpp -o main.o -g
	@g++ -c LinkStack.cpp -o LinkStack.o -g
	@g++ -c ../LinkedList/LinkedList.cpp -o ../LinkedList/LinkedList.o -g
	@g++ -c ../ChainNode/ChainNode.cpp -o ../ChainNode/ChainNode.o -g
	@g++ main.o ../LinkedList/LinkedList.o ../ChainNode/ChainNode.o LinkStack.o -o LabW4 -g

	@./LabW4

	@rm -f *.o ../LinkedList/LinkedList.o ../ChainNode/ChainNode.o LabW4

all: main.o LinkStack.o ../LinkedList/LinkedList.o ../ChainNode/ChainNode.o
	g++ main.o ../LinkedList/LinkedList.o ../ChainNode/ChainNode.o LinkStack.o -o week4 -g

main.o: main.cpp
	g++ -c main.cpp -o main.o -g

LinkStack.o: LinkStack.cpp
	g++ -c LinkStack.cpp -o LinkStack.o -g

../LinkedList/LinkedList.o: ../LinkedList/LinkedList.cpp
	g++ -c ../LinkedList/LinkedList.cpp -o ../LinkedList/LinkedList.o -g

../ChainNode/ChainNode.o: ../ChainNode/ChainNode.cpp
	g++ -c ../ChainNode/ChainNode.cpp -o ../ChainNode/ChainNode.o -g

clean:
	rm -f *.o ../LinkedList/LinkedList.o ../ChainNode/ChainNode.o LabW4