#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a = 0, b = 0, m = 0;
    int arr[25] = { 0 };
    long long decimal = 0, tmp = 0;
    string s;

    cin >> a >> b >> m;
    for (int i = m - 1; i >= 0; i--) {
        cin >> tmp;
        decimal += tmp * pow(a, i);
    }
    while (decimal) {
        tmp = decimal % b;
        decimal /= b;
        s = to_string(tmp) + " " + s;
    }
    cout << s;

    return 0;
}