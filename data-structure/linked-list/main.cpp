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
			this->len = 0;
		};

		void display(){
			struct node<T> cursor;
			cursor.next = this->head;
			while (cursor.next != NULL){
				std::cout << cursor.next->value << ' ';
				cursor.next = cursor.next->next;
			}
			std::cout << std::endl;
		};

		T append(T value, int index){
			struct node<T>* cursor = new node<T>;
			cursor->value = value;
			if (this->len <= 0){
				this->head = cursor;
			}else if (index < 0){
				cursor->next = this->head;
				this->head = cursor;
			}else{
				cursor->next = this->head;
				for (int i=0; i<index && cursor->next->next != NULL; i++){
					cursor->next = cursor->next->next;
				}
				struct node<T>* nextAddr = cursor->next->next;
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
			struct node<T>* cursor;
			cursor = this.head;
			for (int i=0; i<index && cursor->next != NULL; i++){
				cursor = cursor->next;
			}
			return cursor->value;
		};

		T remove(){};

		int length(){
			return this->len;
		};
	private:
		struct node<T>* head;
		int len;
};

int main(){
	//std::cout << "Linked List" << std::endl;

	//struct node<int> nnn;
	//nnn.val = 12;
	//nnn.next = NULL;

	//struct node<int> nn = {11, &nnn};

	//struct node<int> n;
	//n.val = 10;
	//n.next = &nn;

	////display(n);
	////append(n, 5, 0);
	////display(n);
	////append(n, 6, 1);
	////display(n);
	////insert(n, 15, 0);
	////display(n);
	////insert(n, 16, 1);
	////display(n);
	//
	//display(n);

	//append(n, 5, 0);
	//append(n, 6, 1);
	//insert(n, 7, 0);
	//insert(n, 8, 1);

	//display(n);

	LinkedList<int> list;
	list.display();

	list.append(5,1);
	list.display();

	list.insert(6,1);
	list.display();

	list.append(15,0);
	list.display();

	list.insert(16,0);
	list.display();

	list.append(25,list.length());
	list.display();

	list.insert(26,list.length());
	list.display();

	list.append(35,1);
	list.display();

	list.insert(36,1);
	list.display();

	std::cout << list.length() << std::endl;

	return 0;
}
