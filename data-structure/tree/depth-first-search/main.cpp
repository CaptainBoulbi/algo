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
bool dfs(binaryNode<T>* curr, T needle, binaryNode<T>** ptr){
	if (!curr) return false;
	if (curr->value == needle){
		*ptr = curr;
		return true;
	}
	if (curr->value < needle) return dfs(curr->right, needle, ptr);
	return dfs(curr->left, needle, ptr);
}

int main(){
	binaryNode<int> chll = {2, NULL, NULL};
	binaryNode<int> chlr = {7, NULL, NULL};

	binaryNode<int> chrl = {12, NULL, NULL};
	binaryNode<int> chrr = {17, NULL, NULL};

	binaryNode<int> chl = {5, &chll, &chlr};
	binaryNode<int> chr = {15, &chrl, &chrr};

	binaryNode<int> head = {10, &chl, &chr};
	binaryNode<int>* res = NULL;

	if (!dfs(&head, 7, &res)) std::cout << "not found" << std::endl;
	else std::cout << "value 7 at " << res << " * : " << res->value << " & : " << &chlr << std::endl;

	return 0;
}
