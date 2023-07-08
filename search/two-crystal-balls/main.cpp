#include <iostream>
#include <cmath>

int twoCrystalBalls(int arr[], int len){
	int jump = std::floor(std::sqrt(len));
	int i = jump;

	for (; i<len; i+=jump){
		if (arr[i]){
			break;
		}
	}

	i-=jump;

	for (int j=0; j<jump && i<len; j++, i++){
		if (arr[i]){
			return i;
		}
	}
	return -1;
}

int main(){
	int arr1[] = {0,0,0,0,0,0,0,1,1,1};
	int arr2[] = {0,0,0,0,0,1,1,1,1,1};
	int arr3[] = {0,0,0,0,0,0,0,0,0,0};
	int len = sizeof(arr1)/sizeof(arr1[0]);

	std::cout << "arr1 = " << arr1[0];
	for (int i=1; i<len; i++){ std::cout << "," << arr1[i]; }
	std::cout << std::endl;

	std::cout << "index : " << twoCrystalBalls(arr1, len) << std::endl;

	std::cout << "arr2 = " << arr2[0];
	for (int i=1; i<len; i++){ std::cout << "," << arr2[i]; }
	std::cout << std::endl;

	std::cout << "index : " << twoCrystalBalls(arr2, len) << std::endl;

	std::cout << "arr3 = " << arr3[0];
	for (int i=1; i<len; i++){ std::cout << "," << arr3[i]; }
	std::cout << std::endl;

	std::cout << "index : " << twoCrystalBalls(arr3, len) << std::endl;

	return 0;
}
