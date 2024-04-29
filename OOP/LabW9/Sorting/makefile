run:
	@g++ -c main.cpp -o main.o
	@g++ -c Sorting.cpp -o Sorting.o
	@g++ -c ../ArrayList/arrayList.cpp -o ../ArrayList/arrayList.o
	@g++ main.o Sorting.o ../ArrayList/arrayList.o -o Sorting

	@./Sorting

	@rm -f *.o ../ArrayList/arrayList.o Sorting
	
all: main.o Sorting.o
	g++ main.o Sorting.o -o Sorting -g

main.o: main.cpp
	g++ -c main.cpp -o main.o

Sorting.o: Sorting.cpp
	g++ -c Sorting.cpp -o Sorting.o

../ArrayList/arrayList.cpp: ../ArrayList/arrayList.cpp
	g++ -c ../ArrayList/arrayList.cpp -o ../ArrayList/arrayList.o

clean:
	rm -f *.o ../ArrayList/arrayList.o Sorting