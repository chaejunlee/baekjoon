#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[9];

int solve(int n, int m) {
    if (n > M) {
        for (int i = 1; i <= M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return 0;
    }
    for (int i = m; i <= N; i++) {
        arr[n] = i;
        solve(n + 1, i);
    }
    return 0;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
    solve(1, 1);
	return 0;
}
