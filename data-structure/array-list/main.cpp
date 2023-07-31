#include <iostream>
#include <cmath>
#include "ArrayList.hpp"

// https://en.cppreference.com/w/cpp/container/list
// main array in public (access l.array[5] = 9;)

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
	if (this->len <= gap) this->resize(gap);
	return value;
};

int main(){
	ArrayList<int> l(5);
	std::cout << "len : " << l.length() << " cap : " << l.capacity() << std::endl;
	std::cout << "disp : " << l.toString() << std::endl;

	int y = l.capacity()+5;
	for (int i=0; i<y; i++){
		l.set(i,i*i);
		std::cout << "add : " << i*i << std::endl;
	}

	std::cout << "len : " << l.length() << " cap : " << l.capacity() << std::endl;
	std::cout << "disp : " << l.toString() << std::endl;

	//std::cout << "get : " << l.get(l.length()+5) << " at : " << l.length()+5 << std::endl;
	//std::cout << "get : " << l.get(-1) << " at : -1" << std::endl;

	std::cout << "man get : " << l.array[5] << " at 5" << std::endl;
	std::cout << "man get : " << l.array[-1] << " at -1" << std::endl;

	std::cout << "pooped : ";
	for (int i=0; i<10; i++){
		std::cout << l.pop() << ' ';
	}
	std::cout << std::endl;
	std::cout << "len : " << l.length() << " cap : " << l.capacity() << std::endl;
	std::cout << "disp : " << l.toString() << std::endl;

	y = l.capacity()+5;
	for (int i=0; i<y; i++){
		l.set(i,i*i);
		std::cout << "add : " << i*i << std::endl;
	}
	std::cout << "len : " << l.length() << " cap : " << l.capacity() << std::endl;
	std::cout << "disp : " << l.toString() << std::endl;

	std::cout << "char array list" << std::endl;

	ArrayList<char> c(5);

	for (int i=0; i<10; i+=2){
		c.set(i,'c');
		c.set(i+1,'a');
	}

	for (int i=0; i<c.length(); i++){
		std::cout << c.get(i) << ' ';
	}
	std::cout << std::endl;

	// ;{
	std::cout << c.toString() << std::endl;
	std::cout << c.length() << ' ' << c.capacity() << std::endl;

	return 0;
}
