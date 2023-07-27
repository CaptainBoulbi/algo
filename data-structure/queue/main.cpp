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
			this->head = NULL;
			this->tail = this->head;
		};

		T enqueue(T value){
			if (this->tail == NULL){
				this->tail = new node<T>;
				this->tail->value = value;
				this->head = this->tail;
			}else{
				node<T>* newNode = new node<T>;
				newNode->value = value;
				this->tail->next = newNode;
				this->tail = newNode;
			}
			return value;
		};

		T deque(){
			if (this->head != NULL){
				T returnValue = this->head->value;
				node<T>* nodeToRemove = this->head;
				this->head = this->head->next;
				delete nodeToRemove;
				return returnValue;
			}
			return (int)NULL;
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
