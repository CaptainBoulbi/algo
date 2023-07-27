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
			this->len = 0;
		};

		T enqueue(T value){
			this->len++;
			node<T>* newNode = new node<T> {value, NULL};
			if (!this->tail)
				this->head = this->tail = newNode;
			else
				this->tail = this->tail->next = newNode;
			return value;
		};

		T deque(){
			if (!this->head) return (int)NULL;
			this->len--;
			T returnValue = this->head->value;
			node<T>* nodeToRemove = this->head;
			this->head = this->head->next;
			delete nodeToRemove;
			return returnValue;
		};

		T peek(){
			return this->head == NULL ? (int)NULL : this->head->value;
		};

		int length(){
			return this->len;
		};
	private:
		node<T>* head;
		node<T>* tail;
		int len;
};

int main(){

	Queue<int> Q;
	Q.enqueue(5);
	std::cout << Q.length() << " : " << Q.peek() << std::endl;
	Q.enqueue(9);
	std::cout << Q.length() << " : " << Q.peek() << std::endl;
	Q.deque();
	std::cout << Q.length() << " : " << Q.peek() << std::endl;
	Q.deque();
	std::cout << Q.length() << " : " << Q.peek() << std::endl;

	return 0;
}
