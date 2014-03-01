CC = g++
INC = include/
SRC = src/
FLAGS = -lGL -lGLU -lglut -lm -Wall -Werror -g -std=c++11 -I $(INC) 

make:
	$(CC) $(SRC)*.cpp -o rubiks.out $(FLAGS) 
	
add:
	git add README.md LICENSE makefile src/*.cpp include/*.h
