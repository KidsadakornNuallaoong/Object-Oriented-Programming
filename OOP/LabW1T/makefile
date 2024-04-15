all : file1.o file2.o
	@g++ file1.o file2.o -o program

	@./program

	@rm -f *.o program

file1.o : main.cpp
	@g++ -c main.cpp -o file1.o

file2.o : MyCode.cpp
	@g++ -c MyCode.cpp -o file2.o

clean : 
	rm -f *.o program