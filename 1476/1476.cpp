#include <iostream>
using namespace std;

const int E = 15;
const int S = 28;
const int M = 19;
int e, s, m;
int result = 0;

int main(void) {
    ios_base:: sync_with_stdio(0);
    cin.tie(0);
    cin >> e >> s >> m;
    // ans = 15 * E + 1 = 27 * S + 2 = 19 * M + 3
    for (int i = 0; i < 532; i++) {
        result = E * i + e;
        if (!((result - s) % S) && !((result - m) % M)) {
            cout << result;
            break;
        }
    }
    return 0;
}