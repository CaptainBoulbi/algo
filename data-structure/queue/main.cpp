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
			this->head = this->tail = NULL;
		};

		T enqueue(T value){
			node<T>* newNode = new node<T> {value, NULL};
			if (!this->tail)
				this->head = this->tail = newNode;
			else
				this->tail = this->tail->next = newNode;
			return value;
		};

		T deque(){
			if (!this->head) return (int)NULL;
			T returnValue = this->head->value;
			node<T>* nodeToRemove = this->head;
			this->head = this->head->next;
			delete nodeToRemove;
			return returnValue;
		};

		T peek(){
			return this->head == NULL ? (int)NULL : this->head->value;
		};
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
	Q.deque();
	std::cout << Q.peek() << std::endl;

	return 0;
}
