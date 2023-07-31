#include <iostream>
#include <string>
#include <cmath>

template <typename T>
struct node{
	T value;
	struct node<T> *next;
};

template <class T>
class Queue{
	public:
		Queue(){
			this->head = this->tail = NULL;
			this->len = 0;
		};

		T enqueue(T value){
			this->len++;
			node<T>* newNode = new node<T> {value, NULL};
			if (!this->tail)
				this->head = this->tail = newNode;
			else
				this->tail = this->tail->next = newNode;
			return value;
		};

		T deque(){
			if (!this->head) return (int)NULL;
			this->len--;
			T returnValue = this->head->value;
			node<T>* nodeToRemove = this->head;
			this->head = this->head->next;
			delete nodeToRemove;
			if (!this->len) this->tail = NULL;
			return returnValue;
		};

		T peek(){
			return this->head == NULL ? (int)NULL : this->head->value;
		};

		int length(){
			return this->len;
		};
	private:
		node<T>* head;
		node<T>* tail;
		int len;
};

template <class T>
class ArrayList{
	public:
		T* array;
		ArrayList(int capacity);
		~ArrayList();
		std::string toString();
		int length();
		int capacity();
		int resize(int newCapacity);
		T set(int index, T value);
		T get(int index);
		T pop();

	private:
		int len;
		int cap;
};

template <class T>
ArrayList<T>::ArrayList(int capacity){
	this->array = new T[capacity];
	this->cap = capacity;
	this->len = 0;
};

template <class T>
ArrayList<T>::~ArrayList(){
	delete this->array;
};

template <class T>
std::string ArrayList<T>::toString(){
	std::string string;
	for (int i=0; i<this->len; i++){
		string += std::to_string(this->array[i]) + ' ';
	}
	return string;
};

template <class T>
int ArrayList<T>::length(){
	return this->len;
};

template <class T>
int ArrayList<T>::capacity(){
	return this->cap;
};

template <class T>
int ArrayList<T>::resize(int newCapacity){
	this->cap = newCapacity;
	T* newArr = new T[newCapacity];
	for (int i=0; i<newCapacity || i<this->len; i++){
		newArr[i] = this->array[i];
	}
	delete this->array;
	this->array = newArr;
	return newCapacity;
};

template <class T>
T ArrayList<T>::set(int index, T value){
	if (index >= this->len) this->len = index+1;
	if (index >= this->cap) this->resize(index + std::sqrt(index));
	this->array[index] = value;
	return value;
};

template <class T>
T ArrayList<T>::get(int index){
	if (index >= this->len) throw "out bound array";
	return this->array[index];
};

template <class T>
T ArrayList<T>::pop(){
	if (this->len <= 0) throw "pop empty list";
	T value = this->array[this->len-1];
	int gap = this->cap - std::sqrt(this->cap);
	this->len--;
	if (this->len <= gap) this->resize(gap+1);
	return value;
};

template <typename T>
struct binaryNode{
	T value;
	struct binaryNode<T> *left;
	struct binaryNode<T> *right;
};

template <typename T>
ArrayList<T>* bfs(binaryNode<T>* curr){
	ArrayList<T>* arr = new ArrayList<T>(10);
	Queue<binaryNode<T>*> q;
	
	q.enqueue(curr);

	while (q.length()){
		if (curr->left) q.enqueue(curr->left);
		if (curr->right) q.enqueue(curr->right);
		arr->set(arr->length(), q.deque()->value);
		curr = q.peek();
	}
	return arr;
}

int main(){
	binaryNode<int> chll = {20, NULL, NULL};
	binaryNode<int> chlr = {50, NULL, NULL};

	binaryNode<int> chrl = {9, NULL, NULL};
	binaryNode<int> chrr = {7, NULL, NULL};

	binaryNode<int> chl = {10, &chll, &chlr};
	binaryNode<int> chr = {6, &chrl, &chrr};

	binaryNode<int> head = {5, &chl, &chr};

	ArrayList<int>* res = bfs(&head);
	std::cout << res->toString() << std::endl;
	delete res;

	return 0;
}
