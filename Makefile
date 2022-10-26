COMP = clang
FLAGS = -Wall -g

all: Question.o main

Question.o: Question.h Question.c
	$(COMP) -c Question.c -o Out/ObjFiles/$@

main: main.c
	$(COMP) $(FLAGS) -lpthread main.c Out/ObjFiles/Question.o -o Out/Build/$@

clean:
	rm -f Out/ObjFiles/*.o Out/Build/*