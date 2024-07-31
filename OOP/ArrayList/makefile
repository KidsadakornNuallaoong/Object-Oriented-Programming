run: all
	@clear
	@echo Program is running...

	@./program
	@rm -f *.o program

all: main.o arrayList.o
	@g++ main.o arraylist.o -o program -g

main.o: main.cpp
	@g++ -c main.cpp -o main.o -g

arraylist.o: arrayList.cpp
	@g++ -c arrayList.cpp -o arrayList.o -g

clean:
	@rm -f *.o program
	@echo Cleaning success......