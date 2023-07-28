#include <iostream>

template <class T>
class ArrayBuffer{
	public:
		ArrayBuffer(int capacity){
			this->array = new T[capacity];
			this->tail = this->head = capacity/2;
			this->len = 0;
			this->cap = capacity;
		};

		T set(T value,int index){
			if (index >= this->len){
				this->len = index+1;
				this->tail = (this->head + index) % this->cap;
			}else if (index < 0){
				this->len -= index;
				this->head = (this->head + index) % this->cap;
			}
			this->array[(this->head + index) % this->cap] = value;
			return value;
		};

		T get(int index){
			//if (this->head == this->tail) return (T)NULL;
			return this->array[(this->head + index) % this->cap];
		};

		int length(){
			return this->len;
		};

		int capacity(){
			return this->cap;
		};

		std::string toString(){
			std::string string;
			for (int i=0; i<this->len; i++){
				string += std::to_string(this->get(i)) + ' ';
			}
			return string;
		};

	private:
		T* array;
		int head;
		int tail;
		int len;
		int cap;
};

int main(){
	ArrayBuffer<int> ab(10);
	//for (int i=0; i<10; i++){
	//	ab.set(i*i,i);
	//	std::cout << ab.toString() << ';' << ab.length() << ';' << ab.capacity() << std::endl;
	//}

	for (int i=0; i<5; i++){
		ab.set(i*i,i);
		std::cout << ab.toString() << ';' << ab.length() << ';' << ab.capacity() << std::endl;
	}

	for (int i=5; i<10; i++){
		ab.set(i*i,-1);
		std::cout << ab.toString() << ';' << ab.length() << ';' << ab.capacity() << std::endl;
	}

	ab.set(7,7);
	std::cout << ab.toString() << ';' << ab.length() << ';' << ab.capacity() << std::endl;

	return 0;
}
