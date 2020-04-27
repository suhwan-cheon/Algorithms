#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int stu_score[9] = { 1,5,6,2,1,3,4,6,7 };
	sort(stu_score, stu_score+9);
	int max_cnt = 0; int max_num = 0;
	int cnt = 0;
	int num = stu_score[0];
	for (int i = 0; i < 9; i++) {
		if (num == stu_score[i]) {
			cnt++;
			if (cnt > max_cnt) {
				max_cnt = cnt;
				max_num = num;
			}
		}
		else {
			num = stu_score[i];
			cnt = 1;
		}
	}
	printf("%d", max_num);
}

