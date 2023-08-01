#include <iostream>
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

template <class T>
class MinHeap{
	public:
		ArrayList<T>* data;

		MinHeap(){
			this->data = new ArrayList<T>(10);
			this->len = 0;
		};

		~MinHeap(){
			delete this->data;
		};

		T insert(T value){
			this->data->set(this->len, value);
			this->heapifyUp(this->len);
			this->len++;
			return value;
		};

		T remove(){
			if (!this->len) throw "remove on empty heap";
			this->len--;
			T returnValue = this->data->get(this->len);
			if (this->len){
				delete this->data;
				this->data = new ArrayList<T>(10);
				return returnValue;
			}
			this->data->set(0, this->data->get(this->len));
			this->heapifyDown(0);
			return returnValue;
		};

		int length(){
			return this->len;
		};

	private:
		int len;

		void heapifyDown(int index){
			if (index >= this->len) return;

			int Lindex = this->leftChild(index);
			int Rindex = this->rightChild(index);

			if (Lindex >= this->len) return;

			T Lvalue = this->data->get(Lindex);
			T Rvalue = this->data->get(Rindex);
			T value = this->data->get(index);

			if (Lvalue > Rvalue && value > Rvalue){
				this->data->set(index, Rvalue);
				this->data->set(Rindex, value);
				this->heapifyDown(Rindex);
			}else if (Rvalue > Lvalue && value > Lvalue){
				this->data->set(index, Lvalue);
				this->data->set(Lindex, value);
				this->heapifyDown(Lindex);
			}
		}

		void heapifyUp(int index){
			if (index == 0) return;

			int parent = this->parent(index);
			T Pvalue = this->data->get(parent);
			T value = this->data->get(index);

			if (Pvalue < value){
				this->data->set(index, Pvalue);
				this->data->set(parent, value);
				this->heapifyUp(parent);
			}
		};

		int parent(int index){
			return (index -1) / 2;
		};

		int leftChild(int index){
			return index * 2 + 1;
		};

		int rightChild(int index){
			return index * 2 + 2;
		};
};

int main(){
	MinHeap<int> mh;
	mh.insert(5);
	mh.insert(8);
	mh.insert(10);
	mh.insert(0);
	mh.insert(50);

	std::cout << mh.length() << std::endl;

	int len = mh.length();
	for (int i=0; i<len; i++){
		std::cout << mh.data->get(i);
	}
	std::cout << std::endl;

	len = mh.length();
	std::cout << len << std::endl;
	for (int i=0; i<len; i++){
		std::cout << mh.remove() << ' ';
	}
	std::cout << std::endl;

	std::cout << mh.length() << std::endl;

	return 0;
}
