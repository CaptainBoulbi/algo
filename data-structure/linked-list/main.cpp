#include <iostream>
#include <string>

template <typename T>
struct node{
	T value;
	struct node<T> *next;
};

template <class T>
class LinkedList{
	public:
		LinkedList(){
			this->head = NULL;
			this->len = 0;
		};

		std::string toString(){
			if (!this->head) return "empty";
			std::string string;
			node<T>* cursor;
			cursor = this->head;
			while (cursor->next){
				string += std::to_string(cursor->value) + ' ';
				cursor = cursor->next;
			}
			return string;
		};

		T append(T value, int index){
			node<T>* cursor = new node<T>;
			cursor->value = value;
			if (this->len <= 0){
				this->head = cursor;
			}else if (index < 0){
				cursor->next = this->head;
				this->head = cursor;
			}else{
				cursor->next = this->head;
				for (int i=0; i<index && cursor->next->next; i++){
					cursor->next = cursor->next->next;
				}
				node<T>* nextAddr = cursor->next->next;
				cursor->next->next = cursor;
				cursor->next = nextAddr;
			}
			this->len++;
			return cursor->value;
		}

		T insert(T value, int index){
			return this->append(value, index-1);
		}

		T get(int index){
			node<T>* cursor;
			cursor = this->head;
			for (int i=0; i<index && cursor->next; i++){
				cursor = cursor->next;
			}
			return cursor->value;
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
				this->head = this->head->next;
			}else{
				for (int i=0; i<index-1 && cursor->next->next; i++){
					cursor = cursor->next;
				}
				node<T>* nodeToRemove = cursor->next;
				returnValue = cursor->next->value;
				cursor->next = cursor->next->next;
				delete nodeToRemove;
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
	LinkedList<int> list;
	std::cout << list.toString() << std::endl;
	list.append(5,1);
	list.insert(6,1);
	list.append(15,0);
	list.insert(16,0);
	list.append(25,list.length());
	list.insert(26,list.length());
	list.append(35,1);
	list.insert(36,1);
	std::cout << list.toString() << std::endl;
	std::cout << list.length() << std::endl;
	std::cout << list.remove(-1) << std::endl;
	std::cout << list.toString() << std::endl;
	std::cout << list.remove(3) << std::endl;
	std::cout << list.toString() << std::endl;

	LinkedList<char> listc;
	listc.append('a', 0);
	listc.insert('c', 0);
	listc.append('c', 1);
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
	listc.append('h', 0);
	std::cout << listc.toString() << std::endl;
	std::cout << listc.length() << std::endl;

	return 0;
}
