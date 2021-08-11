#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	int coins[6] = {500,100,50,10,5,1};
	int coin = 0;
	N = 1000 - N;
	for (int i = 0; i < 6; i++) {
		coin += N / coins[i];
		N %= coins[i];
	}
	cout << coin << "\n";
	
	return 0;
}