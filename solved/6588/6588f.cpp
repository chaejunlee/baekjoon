#include <bits/stdc++.h>
using namespace std;

int arr[1000001] = { 0, 1 };

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 2; (i * i) < 1000000; i++) {
        if (!arr[i])
            for (int j = i * i; j < 1000000; j += i) {
                arr[j] = 1;
            }
    }

    int n = 0;
    do {
        cin >> n;
        if (n == 0)
            break;
        bool check = false;
        for (int i = 0, j = n; i <= n / 2; i++, j--) {
            if ((i % 2 == 1) && (!arr[i] && !arr[j])) {
                cout << n << " = " << i << " + " << j << "\n";
                check = false;
                break;
            }
            check = true;
        }
        if (check)
            cout << "Goldbach's conjecture is wrong.\n" << "\n";
    } while (1);
    return 0;
}