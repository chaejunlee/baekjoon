#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = 0, result = 0, temp = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp == 1);
        else if (temp == 2)
            result += 1;
        else {
            for (int j = 2; j < temp; j++) {
                if (temp % j == 0) {
                    temp = -1;
                }
            }
            if (temp != -1)
                result += 1;
        }
    }
    cout << result;
    return 0;
}