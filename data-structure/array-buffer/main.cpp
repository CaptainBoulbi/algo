#include <iostream>

template <class T>
class ArrayBuffer{
	public:
		ArrayBuffer(){};

		T set(){};

		T get(){};

		T front(){};

		T back(){};

		T push_front(){};

		T push_back(){};

		T pop_front(){};

		T pop_back(){};

		int resize(){};

		int length(){};

		int capacity(){};

		std::string toString(){};

	private:
		int len;
		int cap;
};

int main(){

	return 0;
}
