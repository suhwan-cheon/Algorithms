#include <iostream>
using namespace std;

//삽입 정렬
void insertionSort(int arr[], int n) {  //배열과 배열 원소의 개수를 받는다
	int temp = 0; //비교할 값을 저장할 변수
	for (int i = 1; i < n; i++) {    //가장 왼쪽 값은 옮겨둔것으로 설정한 후 나머지 n-1개의 원소만 옮김
		temp = arr[i];
		int sort_cnt = i - 1; //저장 공간 변수 index
		while (sort_cnt >= 0 && arr[sort_cnt] > temp) {  //배열범위 0 이상 and 정렬된 부분의 원소가 꺼낸 값보다 클 때
			arr[sort_cnt + 1] = arr[sort_cnt];
			sort_cnt--;
		}
		arr[sort_cnt + 1] = temp;
	}
}
int main()
{
	int arr[5] = { 5,3,1,4,2 };  // 주어진 배열
	int n = 5; // 원소의 개수 	
	insertionSort(arr, n);
	for (int i = 0; i < n; i++) {
		printf("%d ",arr[i]);
	}
	return 0;
}

