#include <iostream>
#include <vector>
bool check[100];
vector <int> a[10];
void dfs(int x) {
	check[x] = true;
	printf("%d", x);
	int n = 10;
	for (int i = 1; i <= n; i++) {
		if (a[x][i] == 1 && check[i] == false) {
			dfs(i);
		}
	}
}
 
void dfs2(int x) {
	check[x] = true;
	printf("%d", x);
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (check[y] == false) {
			dfs2(y);
		}
	}
}
