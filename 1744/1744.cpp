#include <iostream>
#include <algorithm>
using namespace std;

int n, temp;
int pos[10000];
int neg[10000];
int posI = 0, negI = 0;
long long result = 0;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp <= 0) {
            neg[negI++] = temp;
        } else {
            pos[posI++] = temp;
        }
    }
    sort(neg, neg + negI);
    sort(pos, pos + posI);
    reverse(pos, pos + posI);
    for (int i = 0; i < negI; i += 2) {
        if (i + 1 < negI)
            result += neg[i] * neg[i + 1];
        else 
            result += neg[i];
    }
    for (int i = 0; i < posI; i += 2) {
        if (pos[i] == 1 || pos[i + 1] == 1) {
            result += pos[i] + pos[i + 1];
        } else if (i + 1 < posI) {
            result += pos[i] * pos[i + 1];
        } else {
            result += pos[i];
        }
    }
    cout << result;
    return 0;
}