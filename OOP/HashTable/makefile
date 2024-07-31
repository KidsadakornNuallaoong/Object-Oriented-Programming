run:
	@clear
	@g++ -c main.cpp -o main.o
	@echo "\e[1;32m File 1 Success \e[0m"
	@g++ -c HashTable.cpp -o HashTable.o
	@echo "\e[1;32m File 2 Success \e[0m"
	@g++ -c ../ArrayList/arrayList.cpp -o ../ArrayList/arrayList.o
	@echo "\e[1;32m File 3 Success \e[0m"
	@g++ main.o HashTable.o ../ArrayList/arrayList.o -o HashTable
	@clear
	@echo "\e[1;32m Build Success \e[0m"

	@./HashTable

	@rm -f *.o ../ArrayList/arrayList.o HashTable
	@clear
	@echo "\e[1;31m Remove done \e[0m"
	
all: main.o HashTable.o ../ArrayList/arrayList.o
	g++ main.o HashTable.o ../ArrayList/arrayList.o -o HashTable

main.o: main.cpp
	g++ -c main.cpp -o main.o

HashTable.o: HashTable.cpp
	g++ -c HashTable.cpp -o HashTable.o

../ArrayList/arrayList.o: ../ArrayList/arrayList.cpp
	g++ -c ../ArrayList/arrayList.cpp -o ../ArrayList/arrayList.o

clean:
	rm -f *.o ../ArrayList/arrayList.o HashTable