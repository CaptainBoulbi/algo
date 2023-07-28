#include <iostream>

int partition(int arr[], int lo, int hi){
	const int pivot = arr[hi];
	int idx = lo - 1;

	for (int i=lo; i<hi; i++){
		if (arr[i] <= pivot){
			idx++;
			const int tmp = arr[i];
			arr[i] = arr[idx];
			arr[idx] = tmp;
		}
	}

	idx++;
	arr[hi] = arr[idx];
	arr[idx] = pivot;

	return idx;
}

void quickSort(int arr[], int lo, int hi){
	if (lo >= hi){
		return;
	}

	const int pivotIdx = partition(arr, lo, hi);

	quickSort(arr, lo, pivotIdx - 1);
	quickSort(arr, pivotIdx + 1, hi);
}

int main(){
	int arr1[] = {9,5,7,3,8,0,1,5,2,4,6};
	int arr2[] = {0,1,2,5,4,9,8,3,0,1,7};
	int len = sizeof(arr1)/sizeof(arr1[0]);

	std::cout << "arr1 = " << arr1[0];
	for (int i=1; i<len; i++){ std::cout << "," << arr1[i]; }
	std::cout << std::endl;

	quickSort(arr1, 0, len-1);

	std::cout << "trié = " << arr1[0];
	for (int i=1; i<len; i++){ std::cout << "," << arr1[i]; }
	std::cout << std::endl;

	std::cout << std::endl;

	std::cout << "arr2 = " << arr2[0];
	for (int i=1; i<len; i++){ std::cout << "," << arr2[i]; }
	std::cout << std::endl;

	quickSort(arr2, 2, len-2);

	std::cout << "trié = " << arr2[0];
	for (int i=1; i<len; i++){ std::cout << "," << arr2[i]; }
	std::cout << std::endl;

	return 0;
}
