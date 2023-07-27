#include <iostream>

// https://en.cppreference.com/w/cpp/container/list
// main array in public (access l.array[5] = 9;)

template <class T>
class ArrayList{
	public:
		ArrayList(){};

		std::string toString(){};

		T front(){};

		T back(){};

		int empty(){};

		int length(){};

		int capacity(){};

		void clear(){};

		T insert(){};

		T erase(){};

		T push_front(){};

		T push_back(){};

		T pop_front(){};

		T pop_back(){};

		int resize(){};

		void swap(){};

		void merge(){};

		void reverse(){};

		int unique(){};

		void sort(){};

		T get(){};

		T enqueue(){};

		T deque(){};

	private:
		int len;
		int cap;
};

int main(){

	return 0;
}
