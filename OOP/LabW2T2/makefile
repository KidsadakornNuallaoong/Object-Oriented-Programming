run: all
	@clear
	@echo Program is running...

	@./program
	@rm -f *.o program

all: main.o arraylist.o
	@g++ main.o arraylist.o -o program -g

main.o: main.cpp
	@g++ -c main.cpp -o main.o -g

arraylist.o: arraylist.cpp
	@g++ -c arraylist.cpp -o arraylist.o -g

clean:
	@rm -f *.o program
	@echo Cleaning success......