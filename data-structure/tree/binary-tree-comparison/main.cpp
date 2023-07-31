#include <iostream>
#include <string>
#include <cmath>

template <typename T>
struct binaryNode{
	T value;
	struct binaryNode<T> *left;
	struct binaryNode<T> *right;
};

template <typename T>
bool comparison(binaryNode<T>* a, binaryNode<T>* b){
	if (a == NULL && b == NULL) return true;
	if (a == NULL || b == NULL) return false;
	if (a->value != b->value) return false;

	return comparison(a->left, b->left) && comparison(a->right, b->right);
}

int main(){
	binaryNode<int> chll = {20, NULL, NULL};
	binaryNode<int> chlr = {50, NULL, NULL};

	binaryNode<int> chrl = {9, NULL, NULL};
	binaryNode<int> chrr = {7, NULL, NULL};

	binaryNode<int> chl = {10, &chll, &chlr};
	binaryNode<int> chr = {6, &chrl, &chrr};

	binaryNode<int> head = {5, &chl, &chr};
	binaryNode<int> head2 = {5, &chl, &chr};

	if (comparison(&head, &head2)) std::cout << "equals" << std::endl;
	else std::cout << "not equals" << std::endl;

	head2.value = 9;
	if (comparison(&head, &head2)) std::cout << "equals" << std::endl;
	else std::cout << "not equals" << std::endl;

	return 0;
}
