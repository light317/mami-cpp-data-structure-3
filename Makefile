all: build run

build:
	g++ -I ./include/ -o ./lib/StackNode.o -c ./src/StackNode.cpp
	g++ -I ./include/ -o ./lib/Stack.o -c ./src/Stack.cpp
	g++ -I ./include/ -o ./lib/BST.o -c ./src/BST.cpp
	g++ -I ./include/ -o ./lib/BSTNode.o -c ./src/BSTNode.cpp
	g++ -I ./include/ -o ./lib/TreeList.o -c ./src/TreeList.cpp
	g++ -I ./include/ -o ./lib/FileReader.o -c ./src/FileReader.cpp

	g++ -I ./include/ -o ./bin/main  ./lib/Stack.o ./lib/StackNode.o ./lib/BST.o ./lib/BSTNode.o ./lib/TreeList.o ./lib/FileReader.o ./src/main.cpp

run:
	./bin/main