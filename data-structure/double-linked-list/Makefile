FLAGS=-Wall -Wextra -Og -g

all : main

main : main.o
	g++ $(FLAGS) -o main main.o

main.o : main.cpp
	g++ $(FLAGS) -c -o main.o main.cpp

run : all
	./main

clean :
	rm -f *.o main

check :
	cppcheck --enable=all --suppress=missingIncludeSystem -I. .
	flawfinder .

.PHONY : run clean check
