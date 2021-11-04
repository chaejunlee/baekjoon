#include <iostream>
#include <algorithm>
using namespace std;

int n = 0;
int p[1000];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(p, p + n);
    int result = 0;
    for (int i = 0; i < n; i++) {
        result += (n - i) * p[i];
    }
    cout << result;
    return 0;
}