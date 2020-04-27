#include <iostream>
#include <list>
using namespace std;
int main()
{
	list<pair<int, int> > L;
	L.insert(L.begin(), make_pair(1, 2));
	L.emplace(L.begin(), 3, 4);
	
	for (auto it = L.rbegin(); it != L.rend(); it++) {
		cout << it->first << " " << it->second << "\n";
	}
}
