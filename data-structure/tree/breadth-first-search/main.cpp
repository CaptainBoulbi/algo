#include <iostream>
#include <string>
#include <cmath>

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
			if (!this->len) this->tail = NULL;
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

template <typename T>
struct binaryNode{
	T value;
	struct binaryNode<T> *left;
	struct binaryNode<T> *right;
};

template <typename T>
bool bfs(binaryNode<T>* curr, T needle, binaryNode<T>** ptr){
	Queue<binaryNode<T>*> q;
	q.enqueue(curr);

	while (q.length()){
		if (curr->value == needle){
			*ptr = curr;
			return true;	
		}
		if (curr->left) q.enqueue(curr->left);
		if (curr->right) q.enqueue(curr->right);
		q.deque();
		curr = q.peek();
	}
	return false;
}

int main(){
	binaryNode<int> chll = {20, NULL, NULL};
	binaryNode<int> chlr = {50, NULL, NULL};

	binaryNode<int> chrl = {9, NULL, NULL};
	binaryNode<int> chrr = {7, NULL, NULL};

	binaryNode<int> chl = {10, &chll, &chlr};
	binaryNode<int> chr = {6, &chrl, &chrr};

	binaryNode<int> head = {5, &chl, &chr};
	binaryNode<int>* res = NULL;

	if (!bfs(&head, 9, &res)) std::cout << "not found" << std::endl;
	else std::cout << "value 9 at " << res << " * : " << res->value << std::endl;

	return 0;
}
