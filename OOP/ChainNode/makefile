run: 
	@g++ -c main.cpp -o main.o -g
	@g++ -c ChainNode.cpp -o ChainNode.o -g
	@g++ main.o ChainNode.o -o LabW3 -g

	@./LabW3

	@rm -f *.o LabW3

all: main.o ChainNode.o
	g++ main.o ChainNode.o -o week4 -g

main.o: main.cpp ChainNode.cpp
	g++ -c main.cpp -o main.o -g
	g++ -c ChainNode.cpp -o ChainNode.o -g

clean:
	rm -f *.o LabW3
