#include <iostream>
#include <queue>
using namespace std;
bool check[101];
int a[101][101];
int main()
{
	queue<int> q;
	check[1] = true; q.push(1);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		cout << x << "\n";
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if (check[y] == false) {
				check[y] = true; q.push(y);
			}
		}
	}
}
