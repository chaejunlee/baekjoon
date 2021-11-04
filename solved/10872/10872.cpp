#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = 0;
    long long k = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        k *= i;
    }
    cout << k;
    return 0;
}