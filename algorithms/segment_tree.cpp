#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


//make seg_tree -> O(NlogN)
void init(vector<int>& tree, vector<int>& a, int node, int start,
	int end) { //인자 node는 시작 부분을 말함
	if (start == end) { // 리프 노드일 때는 자기 자신이 최소값(노드의 값)
		tree[node] = a[start];
	}
	else {
		init(tree, a, node * 2, start, (start + end) / 2);
		init(tree, a, node * 2 + 1, (start + end) / 2+1, end );
		tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
	} //두 자식의 최소값 : 부모의 노드 값
} 

//구간의 최소값 구하기 (query) -> O(logN)
int query(vector<int>& tree, int node, int start, int end,
	int i, int j) {
	if (i > end || j < start) return -1;
	if (i <= start && end <= j) return tree[node];
	int m1 = query(tree, 2 * node, start, (start + end) / 2, i, j);
	int m2 = query(tree, 2 * node + 1, (start + end) / 2 + 1, end, i, j);
	if (m1 == -1) {
		return m2;
	}
	else if (m2 == -1) {
		return m1;
	}
	else {
		return min(m1, m2);
	}
}

void update(vector<int>& tree, int node, int start, int end, int index,
	int value) {
	if (index < start || end < index) return;
	if (start == end) {
		tree[node] = value; //값 변경
		return;
	}
	update(tree, node * 2, start, (start + end) / 2, index, value);
	update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, value);
	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
int main()
{
	int n; scanf("%d", &n);
	vector<int> a(n+1);
	int h = (int)ceil(log2(n)); //n을 log 씌움
	int tree_size = (1 << (h + 1)); // 트리의 크기는 2 ^ (높이 + 1)
	vector<int> tree(tree_size);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	init(tree, a, 1, 1, n); //0이 아닌 1부터 시작
	int m; scanf("%d", &m);
	while (m--) {
		int cmd; scanf("%d", &cmd);
		int i, j;
		scanf("%d %d", &i, &j);
		if (cmd == 1) { //update
			update(tree, 1, 1, n, i, j);
		}
		else { // print
			printf("%d\n", query(tree, 1, 1, n , i, j));
		}
	}
	return 0;
}

