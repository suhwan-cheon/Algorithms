#include <iostream>
#include <vector>
using namespace std; 
vector<int> a[10];
int main()
{
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		a[u].push_back(v); a[v].push_back(u);
	}
}

/* plus  weight*/

vector<pair<int, int>> b[10];
int weight() {
	int x, y; cin >> x >> y;
	for (int i = 0; i < y; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		b[u].push_back(make_pair(v, w)); b[v].push_back(make_pair(u, w));
	}
}