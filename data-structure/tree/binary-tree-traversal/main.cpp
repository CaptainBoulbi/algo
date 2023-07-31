#include <iostream>
#include <string>
#include <cmath>

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
ArrayList<T>* pre_walk(binaryNode<T>* node, ArrayList<T>* path){
	if (!node) return path;

	path->set(path->length(), node->value);

	pre_walk(node->left, path);
	pre_walk(node->right, path);

	return path;
}

template <typename T>
ArrayList<T>* pre_order_search(binaryNode<T>* head){
	return pre_walk(head, new ArrayList<T>(10));
}

template <typename T>
ArrayList<T>* in_walk(binaryNode<T>* node, ArrayList<T>* path){
	if (!node) return path;

	in_walk(node->left, path);
	path->set(path->length(), node->value);
	in_walk(node->right, path);

	return path;
}

template <typename T>
ArrayList<T>* in_order_search(binaryNode<T>* head){
	return in_walk(head, new ArrayList<T>(10));
}

template <typename T>
ArrayList<T>* post_walk(binaryNode<T>* node, ArrayList<T>* path){
	if (!node) return path;

	post_walk(node->left, path);
	post_walk(node->right, path);

	path->set(path->length(), node->value);

	return path;
}

template <typename T>
ArrayList<T>* post_order_search(binaryNode<T>* head){
	return post_walk(head, new ArrayList<T>(10));
}

int main(){
	binaryNode<int> chll = {20, NULL, NULL};
	binaryNode<int> chlr = {50, NULL, NULL};

	binaryNode<int> chrl = {9, NULL, NULL};
	binaryNode<int> chrr = {7, NULL, NULL};

	binaryNode<int> chl = {10, &chll, &chlr};
	binaryNode<int> chr = {6, &chrl, &chrr};

	binaryNode<int> head = {5, &chl, &chr};

	ArrayList<int>* pre = pre_order_search(&head);
	ArrayList<int>* in = in_order_search(&head);
	ArrayList<int>* post = post_order_search(&head);

	std::cout << pre->toString() << std::endl;
	std::cout << in->toString() << std::endl;
	std::cout << post->toString() << std::endl;

	delete pre;
	delete in;
	delete post;

	return 0;
}
