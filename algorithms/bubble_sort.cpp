#include <iostream>

int main() {
	int mat[5] = { 9,5,2,4,1 };

	//bubble sort
	for (int i = 0; i < 5; i++) {
		for (int j = i; j < 5; j++) {
			if (mat[i] > mat[j]) { //두 수 swap
				int temp = mat[i];
				mat[i] = mat[j];
				mat[j] = temp;
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		printf("%d ", mat[i]);
	}

	return 0;
}
