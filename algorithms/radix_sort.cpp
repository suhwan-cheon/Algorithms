#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void radixSort(vector<int>& v, int n, int k) {
	queue<int> que[10];
	int max = v[0];
	int d = 1; //최대 자리수
	for (int i = 0; i < k; i++) {
		d *= 10;
	}
	int mod = 10;
	int dmin = 1;
	while (dmin <= d) {
		for (int i = 0; i < n; i++) {
			que[(v[i] % mod) / dmin].push(v[i]);
		}

		for (int i = 0, j = 0; i < 10;) {
			if (que[i].size()) {
				v[j++] = que[i].front();
				que[i].pop();
			}
			else i++;
		}
		dmin *= 10;
		mod *= 10;
	}
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	return;
}
int main()
{
	int n; cin >> n;
	int t; cin >> t;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	radixSort(v, n, t);
}
