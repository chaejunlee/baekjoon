#include <iostream>
using namespace std;

int move[][4] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}};
int n, m;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    if (n == 1) {
        cout << 1;
    } else if (n == 2) {
        if (m < 8) {
            cout << (m + 1) / 2;
        } else {
            cout << 4;
        }
    } else {
        if (m < 4) {
            cout << m;
        } else if (m < 7) {
            cout << 4;
        } else {
            cout << m - 2;
        }
    }
    return 0;
}