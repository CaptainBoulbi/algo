#include <iostream>
#include <fstream>
struct point;
#include "ArrayList.hpp"

struct point{
	int x;
	int y;
};

struct path{
	ArrayList<point>* points;
	int length;
};

struct maze{
	char** maze;
	int row;
	int col;
	point start;
	point end;
};

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

void display(maze* maze){
	for (int i=0; i<maze->row; i++){
		for (int y=0; y<maze->col; y++){
			std::cout << maze->maze[i][y];
		}
		std::cout << std::endl;
	}
}

bool walk(maze* maze, point current, path* path){
	std::cout << maze << &current << path << std::endl;
	return true;
};

path* solve(maze* maze){
	path* chemin = new path;
	chemin->points = new ArrayList<point>(10);
	for (int i=0; i<5; i++){
		chemin->points->set(i, {4,i+5});
	}
	chemin->length = 5;

	walk(maze, maze->start, chemin);
	return chemin;
};

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

void displayPath(maze* maze, path* path){
	struct maze solution;
	copie(maze, &solution);
	for (int i=0; i<path->length; i++){
		solution.maze[path->points->get(i).x][path->points->get(i).y] = 'X';
	}
	display(&solution);
}

int main(){
	maze maze;
	open(&maze, "maze.txt");

	std::cout << "Maze :" << std::endl;
	display(&maze);

	std::cout << "Solution :" << std::endl;
	displayPath(&maze, solve(&maze));

	return 0;
}
