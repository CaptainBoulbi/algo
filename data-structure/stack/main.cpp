#include <iostream>

template <typename T>
struct node{
	T value;
	struct node<T> *next;
};

template <class T>
class Stack{
	public:
		Stack(){
			this->head = NULL;
			this->len = 0;
		};
		
		~Stack(){
			delete this->head;
		}

		T push(T value){
			if (!this->head) this->head = new node<T> {value, NULL};
			else this->head = new node<T> {value, this->head};
			this->len++;
			return value;
		};

		T pop(){
			if (!this->head) return (T)NULL;
			this->len--;
			node<T>* nodeToRemove = this->head;
			T returnValue = nodeToRemove->value;
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
		int len;
};

int main(){

	Stack<int> S;
	std::cout << S.length() << " : " << S.peek() << std::endl;
	S.push(5);
	std::cout << S.length() << " : " << S.peek() << std::endl;
	S.push(9);
	std::cout << S.length() << " : " << S.peek() << std::endl;
	std::cout << "pop:" << S.pop() << '\n' << S.length() << " : " << S.peek() << std::endl;
	std::cout << "pop:" << S.pop() << '\n' << S.length() << " : " << S.peek() << std::endl;
	std::cout << "pop:" << S.pop() << '\n' << S.length() << " : " << S.peek() << std::endl;
	S.push(7);
	std::cout << S.length() << " : " << S.peek() << std::endl;

	return 0;
}
