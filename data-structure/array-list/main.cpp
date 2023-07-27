#include <iostream>

// https://en.cppreference.com/w/cpp/container/list
// main array in public (access l.array[5] = 9;)

template <class T>
class ArrayList{
	public:
		ArrayList(){};

		std::string toString(){};

		int length(){};

		int capacity(){};

		int resize(){};

		T set(){};

		T get(){};

	private:
		int len;
		int cap;
};

int main(){

	return 0;
}
