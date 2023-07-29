#include <iostream>
#include <fstream>
#include <unistd.h> 

template <typename T>
struct node{
	T value;
	struct node<T> *next;
};

template <class T>
class Stack{
	public:
		Stack(){
			this->head = NULL;
			this->len = 0;
		};

		T push(T value){
			if (!this->head) this->head = new node<T> {value, NULL};
			else this->head = new node<T> {value, this->head};
			this->len++;
			return value;
		};

		T pop(){
			if (!this->head) throw "pop empty stack";
			this->len--;
			node<T>* nodeToRemove = this->head;
			T returnValue = nodeToRemove->value;
			this->head = this->head->next;
			delete nodeToRemove;
			return returnValue;
		};

		T peek(){
			if (!this->head) throw "peek empty stack";
			return this->head->value;
		};

		int length(){
			return this->len;
		};
	private:
		node<T>* head;
		int len;
};

struct point{
	int x;
	int y;
};

struct maze{
	char** maze;
	int row;
	int col;
	point start;
	point end;
};

struct dirr{
	int length = 4;
	int x[4] = {-1,0,1,0};
	int y[4] = { 0,1,0,-1};
};

dirr dirr;

void init(maze* maze){
	maze->maze = new char*[maze->row];
	for (int i=0; i<maze->row; i++){
		maze->maze[i] = new char[maze->col];
	}
}

void open(maze* maze, std::string path){
	std::ifstream file(path);
	std::string line;

	getline(file, line);
	maze->col = stoi(line);
	getline(file, line);
	maze->row = stoi(line);

	init(maze);

	for (int i=0; getline(file, line) || i<maze->row; i++){
		for (int y=0; y<maze->col; y++){
			maze->maze[i][y] = line[y];
			if (line[y] == 'S') maze->start = {i, y};
			else if (line[y] == 'E') maze->end = {i, y};
		}
	}
}

void copie(maze* original, maze* copie){
	copie->col = original->col;
	copie->row = original->row;
	copie->start = original->start;
	copie->end = original->end;
	init(copie);
	for (int i=0; i<copie->row; i++){
		for (int y=0; y<copie->col; y++){
			copie->maze[i][y] = original->maze[i][y];
		}
	}
}

void display(maze* maze){
	for (int i=0; i<maze->row; i++){
		for (int y=0; y<maze->col; y++){
			std::cout << maze->maze[i][y];
		}
		std::cout << std::endl;
	}
}

void displayPath(maze* maze, Stack<point>* path){
	struct maze solution;
	copie(maze, &solution);
	int len = path->length();
		std::cout << "\033[" << maze->row << "E";
	for (int i=0; i<len; i++){
		solution.maze[path->peek().x][path->pop().y] = '.';
		std::cout << "\033[" << maze->row << "F";
		display(&solution);
		usleep(50000);
	}
}

bool walk(maze* maze, point current, Stack<point>* path){
	if (current.x < 0 || current.x >= maze->row ||
		current.y < 0 || current.y >= maze->col){
		return false;
	}
	if (maze->maze[current.x][current.y] == '#'){
		return false;
	}
	if (maze->maze[current.x][current.y] == 'X'){
		return false;
	}
	if (current.x == maze->end.x && current.y == maze->end.y){
		path->push(current);
		return true;
	}

	maze->maze[current.x][current.y] = 'X';

	for (int i=0; i<4; i++){
		if (walk(maze, {current.x+dirr.x[i],current.y+dirr.y[i]}, path)){
			path->push(current);
			return true;
		}
	}

	return false;
};

Stack<point>* solve(maze* maze){
	Stack<point>* chemin = new Stack<point>;
	struct maze solution;
	copie(maze, &solution);
	walk(&solution, maze->start, chemin);
	return chemin;
};

int main(){
	maze maze;
	open(&maze, "maze.txt");

	std::cout << "Maze :" << std::endl;
	display(&maze);

	std::cout << "Solution :" << std::endl;
	Stack<point>* path = solve(&maze);
	displayPath(&maze, path);
	delete path;

	return 0;
}
