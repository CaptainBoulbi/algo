#include <iostream>

template<typename T>
T min(T a, T b){
	return a<b ? a : b;
}

template <class T>
class ArrayBuffer{
	public:
		explicit ArrayBuffer(int capacity){
			this->array = new T[capacity];
			this->tail = this->head = capacity/2;
			this->len = 0;
			this->cap = capacity;
		};

		~ArrayBuffer(){
			delete this->array;
		}

		T set(T value,int index){
			int indexValue = (this->head + index) % this->cap;
			if (index >= this->len){
				this->array[indexValue] = value;
				this->tail = indexValue;
				this->len = min(this->cap, index+1);
			}else if (index < 0){
				this->array[indexValue] = value;
				this->head = indexValue;
				this->len = min(this->cap, this->len-index);
			}else{
				this->array[indexValue] = value;
			}
			return value;
		};

		T get(int index){
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

		void display(){
			for (int i=0; i<this->cap; i++){
				std::cout << this->array[i] << ' ';
			}
			std::cout << std::endl;
		}

	private:
		T* array;
		int head;
		int tail;
		int len;
		int cap;
};

int main(){
	ArrayBuffer<int> ab(10);

	for (int i=0; i<10; i++){
		ab.set(i*i,i);
		std::cout << i << ';' << ab.toString() << ';' << ab.length() << ';' << ab.capacity() << std::endl;
	}

	// not throw error when head and tail pass through
	ab.set(77,-2);
	ab.set(777,2);

	ab.display();

	return 0;
}
