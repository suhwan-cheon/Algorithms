#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int ind[32001];
vector<int>v[32001];
int main()
{
	queue<int> q;
	int n, m; scanf("%d %d", &n, &m);
	
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		ind[b] += 1;
		v[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) {
			q.push(i);
		}
	}
	vector<int> ans;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		printf("%d ", x);
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i];
			ind[y] -= 1; //한 단계씩 낮추면서
			if (ind[y] == 0) {
				q.push(y);
			}
		}
	}

	return 0;
}
