#include <iostream>

// insertAt(item T, int n) : void
// remove(item T) : void
// removeAt(int n)
// append(item T) : void
// insert(item T) : void
// get(int n) : int

template <typename T>
struct node{
	T val;
	struct node<T> *next;
};

template <typename T>
T append(node<T> node, T value, int index){
	struct node<T>* cursor;
	cursor = (node<T>*) malloc(16);
	cursor->val = value;
	cursor->next = &node;
	for (int i=0; i<index; i++){
		cursor->next = cursor->next->next;
	}
	struct node<T>* nextAddr = cursor->next->next;
	cursor->next->next = cursor;
	cursor->next = nextAddr;
	return cursor->val;
}

template <typename T>
T insert(node<T> node, T value, int index){
	return append(node, value, index-1);
}

template <typename T>
T get(node<T> node, int index){
	struct node<T> cursor;
	cursor.next = &node;
	for (int i=0; i<index; i++){
		cursor.next = cursor.next->next;
	}
	return cursor.next->val;
};

template <typename T>
T remove(){};

template <typename T>
void display(node<T> node){
	struct node<T> cursor;
	cursor.next = &node;
	while (cursor.next != NULL){
		std::cout << cursor.next->val << ' ';
		cursor.next = cursor.next->next;
	}
	std::cout << std::endl;
};


int main(){
	std::cout << "Linked List" << std::endl;

	struct node<int> n1;
	n1.val = 10;
	n1.next = NULL;

	struct node<int> n2;
	n2.val = 9;
	n2.next = &n1;

	struct node<int> n3;
	n3.val = 8;
	n3.next = &n2;

	struct node<int> n4;
	n4.val = 7;
	n4.next = &n3;

	display(n4);
	insert(n4, 5, 2);
	display(n4);
	insert(n4, 1, 3);
	display(n4);

	return 0;
}
