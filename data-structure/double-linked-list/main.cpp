#include <iostream>
#include <string>

template <typename T>
struct node{
	T value;
	struct node<T> *next;
	struct node<T> *prev;
};

template <class T>
class DoubleLinkedList{
	public:
		DoubleLinkedList(){
			this->head = NULL;
			this->len = 0;
		};

		std::string toString(){
			if (!this->head) return "empty";
			std::string string;
			node<T>* cursor;
			cursor = this->head;
			int tlen = this->len;
			for (int i=0; i<tlen; i++){
				string += std::to_string(cursor->value) + ' ';
				cursor = cursor->next;
			}
			return string;
		};

		T insert(T value, int index){
			index--;
			node<T>* cursor = new node<T> {value, NULL, NULL};
			if (this->len <= 0) this->head = cursor;
			else if (index < 0){
				cursor->next = this->head;
				this->head->prev = cursor;
				this->head = cursor;
			}else{
				cursor->next = this->head;
				for (int i=0; i<index && cursor->next->next; i++){
					cursor->next = cursor->next->next;
				}
				cursor->prev = cursor->next;
				cursor->next = cursor->next->next;
				cursor->prev->next = cursor;
				if (cursor->next) cursor->next->prev = cursor;
			}
			this->len++;
			return value;
		}

		T get(int index){
			node<T>* cursor;
			cursor = this->head;
			for (int i=0; i<index && cursor->next; i++){
				cursor = cursor->next;
			}
			return cursor->value;
		};

		T set(T value, int index){
			node<T>* cursor;
			cursor = this->head;
			for (int i=0; i<index && cursor->next; i++){
				cursor = cursor->next;
			}
			cursor->value = value;
			return value;
		};

		T remove(int index){
			if (!this->len){
				this->head = NULL;
				return (T)NULL;
			}
			node<T>* cursor = this->head;
			T returnValue;
			if (index <= 0){
				returnValue = cursor->value;
				if (this->head->next) this->head = this->head->next;
				this->head->prev = NULL;
			}else{
				for (int i=0; i<index && cursor->next; i++){
					cursor = cursor->next;
				}
				returnValue = cursor->value;
				if (cursor->next) cursor->next->prev = cursor->prev;
				if (cursor->prev) cursor->prev->next = cursor->next;
				delete cursor;
			}
			this->len--;
			return returnValue ;
		};

		int length(){
			return this->len;
		};
	private:
		node<T>* head;
		int len;
};

int main(){
	DoubleLinkedList<int> list;
	std::cout << list.toString() << std::endl;
	list.insert(5,0);
	std::cout << list.toString() << std::endl;
	list.set(4,0);
	std::cout << list.toString() << std::endl;
	list.insert(6,1);
	std::cout << list.toString() << std::endl;
	list.insert(15,0);
	std::cout << list.toString() << std::endl;
	list.insert(16,0);
	std::cout << list.toString() << std::endl;
	list.insert(25,list.length());
	std::cout << list.toString() << std::endl;
	list.set(24,list.length());
	std::cout << list.toString() << std::endl;
	list.insert(26,list.length());
	std::cout << list.toString() << std::endl;
	list.insert(35,1);
	std::cout << list.toString() << std::endl;
	list.insert(36,1);
	std::cout << list.toString() << std::endl;
	std::cout << list.length() << std::endl;
	std::cout << list.remove(-1) << std::endl;
	std::cout << list.toString() << std::endl;
	std::cout << list.remove(3) << std::endl;
	std::cout << list.toString() << std::endl;

	DoubleLinkedList<char> listc;
	listc.insert('c', 0);
	listc.insert('a', 1);
	listc.insert('c', 2);
	listc.insert('a', 3);
	std::cout << listc.toString() << std::endl;
	std::cout << listc.length() << std::endl;
	std::cout << listc.remove(listc.length()+1) << std::endl;
	std::cout << listc.toString() << std::endl;

	for (int i=0; i<listc.length(); i++){
		std::cout << listc.get(i);
	}
	std::cout << std::endl;

	std::cout << listc.length() << std::endl;

	int y = listc.length()+1;
	for (int i=0; i<y; i++){
		std::cout << listc.remove(0) << std::endl;
	}
	listc.insert('h', 0);
	std::cout << listc.toString() << std::endl;
	std::cout << listc.length() << std::endl;

	return 0;
}
