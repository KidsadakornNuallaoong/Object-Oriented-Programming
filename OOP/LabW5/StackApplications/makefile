run:
	@g++ -c main.cpp -o main.o -g
	@g++ -c ../LinkedList/LinkedList.cpp -o ../LinkedList/LinkedList.o -g
	@g++ -c ../LinkStack/LinkStack.cpp -o ../LinkStack/LinkStack.o -g
	@g++ -c ../ChainNode/ChainNode.cpp -o ../ChainNode/ChainNode.o -g
	@g++ main.o ../LinkedList/LinkedList.o ../LinkStack/LinkStack.o ../ChainNode/ChainNode.o -o StackApplications -g

	@./StackApplications

	@rm -f *.o ../LinkedList/LinkedList.o ../LinkStack/LinkStack.o ../ChainNode/ChainNode.o StackApplications

all: main.o ../LinkedList/LinkedList.o ../LinkStack/LinkStack.o ../ChainNode/ChainNode.o
	g++ main.o ../LinkedList/LinkedList.o ../LinkStack/LinkStack.o ../ChainNode/ChainNode.o -o StackApplications -g

main.o: main.cpp
	g++ -c main.cpp -o main.o -g
../LinkedList/LinkedList.o: ../LinkedList/LinkedList.cpp
	g++ -c ../LinkedList/LinkedList.cpp -o ../LinkedList/LinkedList.o -g
../LinkStack/LinkStack.o: ../LinkStack/LinkStack.cpp
	g++ -c ../LinkStack/LinkStack.cpp -o ../LinkStack/LinkStack.o -g
../ChainNode/ChainNode.o: ../ChainNode/ChainNode.cpp
	g++ -c ../ChainNode/ChainNode.cpp -o ../ChainNode/ChainNode.o -g

clean: 
	rm -f *.o ../LinkedList/LinkedList.o ../LinkStack/LinkStack.o ../ChainNode/ChainNode.o StackApplications