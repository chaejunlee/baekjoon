#include <bits/stdc++.h>
using namespace std;

int arr[1000001] = { 0, 1 };

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long a = 0, b = 0;
    cin >> a >> b;
    for (int i = 2; (i * i) < b; i++) {
        for (int j = i * i; j <= b; j += i) {
            arr[j] = 1;
        }
    }
    for (int i = a; i <= b; i++)
        if (!arr[i])
            cout << i << '\n';
    return 0;
}