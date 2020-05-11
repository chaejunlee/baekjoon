#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
vector <pair<int, string>> v;

bool cmp(pair<int, string> a, pair<int, string> b) {
	if (a.first < b.first)
		return true;
	else if (a.first == b.first)
		return false;
	else
		return false;
}

int main(void) {
	
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	stable_sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
	return 0;
}