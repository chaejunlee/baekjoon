#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    int k = (n % 10) * 10 + (((n / 10) + (n % 10)) % 10);
    
    int cnt = 1;
    while (k != n) {
        k = (k % 10) * 10 + (((k / 10) + (k % 10)) % 10);
        cnt++;
    }
    cout << cnt << "\n";
    return 0;
}
