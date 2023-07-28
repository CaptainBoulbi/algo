PATHLIB=../data-structure/array-list
FLAGS=-Wall -Wextra -Og -g -I$(PATHLIB)

all : main

main : main.o ArrayList.o
	g++ $(FLAGS) -o main main.o ArrayList.o

main.o : main.cpp
	g++ $(FLAGS) -c -o main.o main.cpp

ArrayList.o : $(PATHLIB)/main.cpp
	g++ $(FLAGS) -c -o $@ $^

run : all
	./main

clean :
	rm -f *.o main

check :
	cppcheck --enable=all --suppress=missingIncludeSystem -I. .
	flawfinder .

.PHONY : run clean check
