run: all
	@clear
	@echo Program is running...

	@./LabW4
	@rm -f *.o ../ArrayList/ArrayList.o LabW4

all: main.o ArrayStack.o ../ArrayList/arrayList.o
	@g++ main.o ArrayStack.o ../ArrayList/arrayList.o -o LabW4 -g

main.o: main.cpp
	@g++ -c main.cpp -o main.o -g

ArrayStack.o: ArrayStack.cpp
	@g++ -c ArrayStack.cpp -o ArrayStack.o -g

../ArrayList/arrayList.o: ../ArrayList/arrayList.cpp
	@g++ -c ../ArrayList/arrayList.cpp -o ../ArrayList/arrayList.o -g

clean:
	@rm -f *.o ../ArrayList/ArrayList.o LabW4
	@echo Cleaning success......