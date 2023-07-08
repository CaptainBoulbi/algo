#include <iostream>

int linearSearch(int arr[], int len, int v){
	for (int i=0; i<len; i++){
		if (arr[i] == v){
			return i;
		}
	}
	return -1;
}

int main(){
	int arr[] = {9,5,7,3,8,0,1,5,2,4,6};
	int len = sizeof(arr)/sizeof(arr[0]);

	std::cout << arr[0];
	for (int i=1; i<len; i++){ std::cout << "," << arr[i]; }
	std::cout << std::endl;

	std::cout << "index of 8 : " << linearSearch(arr, len, 8) << std::endl;
	std::cout << "index of 5 : " << linearSearch(arr, len, 5) << std::endl;
	std::cout << "index of 11 : " << linearSearch(arr, len, 11) << std::endl;

	return 0;
}
