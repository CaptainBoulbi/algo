#include <iostream>

template <typename T>
struct node{
	T val;
	struct node<T> *next;
};

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

template <typename T>
T append(node<T> node, T value, int index){
	struct node<T>* cursor = new struct node<T>;
	cursor->val = value;
	cursor->next = &node;
	for (int i=0; i<index && cursor->next->next != NULL; i++){
		cursor->next = cursor->next->next;
	}
	struct node<T>* nextAddr = cursor->next->next;
	cursor->next->next = cursor;
	cursor->next = nextAddr;
	display(*cursor);
	return cursor->val;
}

template <typename T>
T insert(node<T> node, T value, int index){
	return append(node, value, index-1);
}

template <typename T>
T get(node<T> node, int index){
	struct node<T>* cursor;
	cursor = &node;
	for (int i=0; i<index && cursor->next != NULL; i++){
		cursor = cursor->next;
	}
	return cursor->val;
};

template <typename T>
T remove(){};

template <typename T>
int length(node<T> node){
	int len = 0;
	struct node<T>* cursor = &node;
	while (cursor->next != NULL){
		cursor->next = cursor->next->next;
		len++;
	}
	return len+1;
};

int main(){
	std::cout << "Linked List" << std::endl;

	struct node<int> nnn;
	nnn.val = 12;
	nnn.next = NULL;

	struct node<int> nn = {11, &nnn};

	struct node<int> n;
	n.val = 10;
	n.next = &nn;

	//display(n);
	//append(n, 5, 0);
	//display(n);
	//append(n, 6, 1);
	//display(n);
	//insert(n, 15, 0);
	//display(n);
	//insert(n, 16, 1);
	//display(n);
	
	display(n);

	append(n, 5, 0);
	append(n, 6, 1);
	insert(n, 7, 0);
	insert(n, 8, 1);

	display(n);

	return 0;
}
