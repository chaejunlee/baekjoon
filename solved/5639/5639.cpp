#include <bits/stdc++.h>
using namespace std;

vector<int> preorder;

int solve(int left, int right) {
	// cout << left << " " << right << "\n";
	if (left == right) return 0;
	
	int root = preorder[left];
	
	int divider = left + 1;
	for ( ; divider < right; divider++) {
		if (root < preorder[divider]) break;
	}
	solve(left + 1, divider);
	solve(divider, right);
	cout << root << "\n";
	
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int temp;
	cin >> temp;
	while(!cin.eof()) {
        preorder.push_back(temp);
		cin >> temp;
	}
	solve(0, preorder.size());
	
	
	return 0;
}