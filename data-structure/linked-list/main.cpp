#include <iostream>

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

		void display(){
			node<T> cursor;
			cursor.next = this->head;
			while (cursor.next){
				std::cout << cursor.next->value << ' ';
				cursor.next = cursor.next->next;
			}
			std::cout << std::endl;
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
	list.display();
	list.append(5,1);
	list.insert(6,1);
	list.append(15,0);
	list.insert(16,0);
	list.append(25,list.length());
	list.insert(26,list.length());
	list.append(35,1);
	list.insert(36,1);
	list.display();
	std::cout << list.length() << std::endl;
	std::cout << list.remove(-1) << std::endl;
	list.display();
	std::cout << list.remove(3) << std::endl;
	list.display();

	LinkedList<char> listc;
	listc.append('a', 0);
	listc.insert('c', 0);
	listc.append('c', 1);
	listc.insert('a', 3);
	listc.display();
	std::cout << listc.length() << std::endl;
	std::cout << listc.remove(listc.length()+1) << std::endl;
	listc.display();

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
	listc.display();
	std::cout << listc.length() << std::endl;

	return 0;
}
