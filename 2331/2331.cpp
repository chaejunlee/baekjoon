#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int A = 0, P = 0;
    cin >> A >> P;
    vector<long> v;

    long temp = A, result = 0, cnt = 0;
    v.push_back(temp);
    while (temp != -1) {
        result = 0;
        while (temp) {
            result += pow(temp % 10, P);
            temp /= 10;
        }
        temp = result;
        for (cnt = 0; cnt < v.size(); cnt++) {
            if (v[cnt] == temp) {
                temp = -1;
                break;
            }
        }
        v.push_back(temp);
    }
    cout << cnt;

    return 0;
}