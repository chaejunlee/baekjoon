#include <iostream>
#include <vector>
using namespace std;

long getGCD(long a, long b) {
    if (b == 0)
        return a;
    else
        return getGCD(b, a % b);
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 0, n = 0;
    long gcd = 0, input = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<long> v;
        v.resize(n);
        gcd = 0;
        for (int j = 0; j < n; j++) {
            cin >> v[j];
        }
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                gcd += getGCD(v[j], v[k]);
                // cout << "j: " << j << " k: " << k << " gcd: " << gcd << "\n";
            }
        }
        cout << gcd << "\n";
    }
}