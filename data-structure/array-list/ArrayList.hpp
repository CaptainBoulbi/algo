#ifndef ARRAYLIST_H
#define ARRAYLIST_H

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

	private:
		int len;
		int cap;
};

#endif
