#include <bits/stdc++.h>
using namespace std;

long long int solve(int a, int b, int c) {
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        return a % c;
    }
    long long int temp = solve(a, b / 2, c) % c;
    long long int res = temp * temp % c;
    if (b % 2) {
        res = res * a;
    }
    return res % c;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, i;
    cin >> a >> b >> c;
    cout << solve(a, b, c);
}