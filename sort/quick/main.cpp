#include <iostream>

void quickSort(int arr[], int len){
	len = arr[0];
	len++;
}

int main(){
	int arr1[] = {9,5,7,3,8,0,1,5,2,4,6};
	int arr2[] = {0,1,2,5,4,9,8,3,0,1,7};
	int len = sizeof(arr1)/sizeof(arr1[0]);

	std::cout << "arr1 = " << arr1[0];
	for (int i=1; i<len; i++){ std::cout << "," << arr1[i]; }
	std::cout << std::endl;

	quickSort(arr1, len);

	std::cout << "trié = " << arr1[0];
	for (int i=1; i<len; i++){ std::cout << "," << arr1[i]; }
	std::cout << std::endl;

	std::cout << std::endl;

	std::cout << "arr2 = " << arr2[0];
	for (int i=1; i<len; i++){ std::cout << "," << arr2[i]; }
	std::cout << std::endl;

	quickSort(arr2, len);

	std::cout << "trié = " << arr2[0];
	for (int i=1; i<len; i++){ std::cout << "," << arr2[i]; }
	std::cout << std::endl;

	return 0;
}
