#include <iostream>

// array doit etre trié

int binarySearch(int arr[], int low, int high, int value){
	int middle;
	do{
		middle = low + (high-low)/2;
		if (value == arr[middle]){
			return middle;
		}else if (value > arr[middle]){
			low = middle + 1;
		}else{
			high = middle;
		}
	}while(low < high);
	return -1;
}

int main(){
	int arr[] = {0,2,4,6,8,10,12,14,16,18};
	int len = sizeof(arr)/sizeof(arr[0]);

	std::cout << "arr = " << arr[0];
	for (int i=1; i<len; i++){ std::cout << "," << arr[i]; }
	std::cout << std::endl;

	std::cout << "index of 0 : " << binarySearch(arr, 0, len, 0) << std::endl;
	std::cout << "index of 6 : " << binarySearch(arr, 0, len, 6) << std::endl;
	std::cout << "index of 14 : " << binarySearch(arr, 0, len, 14) << std::endl;
	std::cout << "index of 18 : " << binarySearch(arr, 0, len, 18) << std::endl;
	std::cout << "index of 11 : " << binarySearch(arr, 0, len, 11) << std::endl;

	return 0;
}
