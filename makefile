FLAGS = -lGL -lGLU -lglut -lassimp -lSOIL -w -std=c++11
PROG_NAME = test

all:
	g++ main.cpp loaders.cpp ship.cpp missile.cpp $(FLAGS) -o $(PROG_NAME) 

