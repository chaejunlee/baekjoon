#include <iostream>
using namespace std;

int n, m, k;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    int team = 0;
    if (n > 2 * m) {
        team = m;
        k -= (n - 2 * m);
    } else {
        team = n / 2;
        k -= n % 2;
        k -= m - n / 2;
    }
    while (k > 0) {
        team--;
        k -= 3;
    }
    cout << team;
    return 0;
}