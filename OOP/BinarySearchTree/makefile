run:
	@clear
	@g++ -c main.cpp -o main.o
	@echo "\e[1;32m File 1 Success \e[0m"
	@g++ -c BinarySearchTree.cpp -o BinarySearchTree.o
	@echo "\e[1;32m File 2 Success \e[0m"
	@g++ -c ../BinaryTreeNode/BinaryTreeNode.cpp -o ../BinaryTreeNode/BinaryTreeNode.o
	@echo "\e[1;32m File 3 Success \e[0m"
	@g++ main.o BinarySearchTree.o ../BinaryTreeNode/BinaryTreeNode.o -o BinarySearchTree
	@clear
	@echo "\e[1;32m Build Success \e[0m"

	@./BinarySearchTree

	@rm -f *.o ../BinaryTreeNode/BinaryTreeNode.o BinarySearchTree
	@clear
	@echo "\e[1;31m Remove done \e[0m"
	
all: main.o BinarySearchTree.o ../BinaryTreeNode/BinaryTreeNode.o
	g++ main.o BinarySearchTree.o ../BinaryTreeNode/BinaryTreeNode.o -o BinarySearchTree

main.o: main.cpp
	g++ -c main.cpp -o main.o

BinarySearchTree.o: BinarySearchTree.cpp
	g++ -c BinarySearchTree.cpp -o BinarySearchTree.o

../BinaryTreeNode/BinaryTreeNode.o: ../BinaryTreeNode/BinaryTreeNode.cpp
	g++ -c ../BinaryTreeNode/BinaryTreeNode.cpp -o ../BinaryTreeNode/BinaryTreeNode.o

clean:
	rm -f *.o ../BinaryTreeNode/BinaryTreeNode.o BinarySearchTree