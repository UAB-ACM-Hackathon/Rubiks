CC = g++
INC = include/
SRC = src/
FLAGS = -lGL -lGLU -lglut -lm -Wall -Werror -g -std=c++11 -I $(INC) 

make:
	$(CC) $(SRC)*.cpp -o rubiks.out $(FLAGS) 
	
run:
	./rubiks.out
	
add:
	git add README.md LICENSE makefile src/*.cpp include/*.h meshes/*.off
	
push:
	git push -u origin master
