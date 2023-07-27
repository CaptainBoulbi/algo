#include <iostream>

template <typename T>
struct node{
	T value;
	struct node<T> *next;
};

template <class T>
class Queue{
	public:
		Queue(){
			//this->head = new node<T>;
			//this->tail = this->head;
		};

		T enqueue(T value){
			
		};

		T deque(){};

		T peek(){};

	private:
		node<T>* head;
		node<T>* tail;
};

int main(){

	Queue<int> Q;
	Q.enqueue(5);
	std::cout << Q.peek() << std::endl;
	Q.enqueue(9);
	std::cout << Q.peek() << std::endl;
	Q.deque();
	std::cout << Q.peek() << std::endl;

	return 0;
}
