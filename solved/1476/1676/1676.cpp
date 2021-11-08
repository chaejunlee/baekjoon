#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = 0, two = 0, five = 0, temp = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        temp = i;
        while (!(temp % 5)) {
            five++;
            temp /= 5;
        }
    }
    cout << five;

    return 0;
}