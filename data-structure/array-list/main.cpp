#include <iostream>
#include <cmath>

// https://en.cppreference.com/w/cpp/container/list
// main array in public (access l.array[5] = 9;)

template <class T>
class ArrayList{
	public:
		T* array;

		ArrayList(int capacity){
			this->array = new T[capacity];
			this->cap = capacity;
			this->len = 0;
		};

		std::string toString(){
			std::string string;
			for (int i=0; i<this->len; i++){
				string += std::to_string(this->array[i]) + ' ';
			}
			return string;
		};

		int length(){
			return this->len;
		};

		int capacity(){
			return this->cap;
		};

		int resize(int newCapacity){
			this->cap = newCapacity;
			T* newArr = new T[newCapacity];
			for (int i=0; i<newCapacity; i++){
				newArr[i] = this->array[i];
			}
			delete this->array;
			this->array = newArr;
			return newCapacity;
		};

		T set(int index, T value){
			if (index >= this->len) this->len = index+1;
			if (index >= this->cap) this->resize(this->cap + std::sqrt(this->cap));
			this->array[index] = value;
			return value;
		};

		T get(int index){
			// sould throw an error
			if (index >= this->len) return (T)NULL;
			return this->array[index];
		};

	private:
		int len;
		int cap;
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

	// sould throw an error
	std::cout << "get : " << l.get(l.length()+5) << " at : " << l.length()+5 << std::endl;
	std::cout << "get : " << l.get(-1) << " at : -1" << std::endl;

	std::cout << "man get : " << l.array[5] << " at 5" << std::endl;
	std::cout << "man get : " << l.array[-1] << " at -1" << std::endl;

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
