#include <iostream>

void bubbleSort(int arr[], int len){
	int change;
	int count = 1;
	int swap;
	do{
		change = 0;
		for (int i=0; i<len-count; i++){
			if (arr[i] > arr[i+1]){
				swap = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = swap;
				change = 1;
			}
		}
		count++;
	}while (change);
}

int main(){
	int arr1[] = {9,5,7,3,8,0,1,5,2,4,6};
	int arr2[] = {0,1,2,5,4,9,8,3,0,1,7};
	int len = sizeof(arr1)/sizeof(arr1[0]);

	std::cout << "arr1 = " << arr1[0];
	for (int i=1; i<len; i++){ std::cout << "," << arr1[i]; }
	std::cout << std::endl;

	bubbleSort(arr1, len);

	std::cout << "trié = " << arr1[0];
	for (int i=1; i<len; i++){ std::cout << "," << arr1[i]; }
	std::cout << std::endl;

	std::cout << std::endl;

	std::cout << "arr2 = " << arr2[0];
	for (int i=1; i<len; i++){ std::cout << "," << arr2[i]; }
	std::cout << std::endl;

	bubbleSort(arr2, len);

	std::cout << "trié = " << arr2[0];
	for (int i=1; i<len; i++){ std::cout << "," << arr2[i]; }
	std::cout << std::endl;

	return 0;
}
