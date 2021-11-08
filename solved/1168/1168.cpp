#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0, k = 0;
	vector<int> v;

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		v.push_back(i);

	int pointer = k - 1;
	cout << "<";
	for (int i = 0; i < n; i++) {
		cout << v[pointer];
		if (i < n - 1)
			cout << ", ";
		v.erase(v.begin() + pointer);
		if (v.size())
			pointer = (pointer + k - 1) % v.size();
	}
	cout << ">";

	return 0;
}