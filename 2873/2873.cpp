#include <iostream>
using namespace std;

int r, c, x, y, temp = 987654321;
int land[1002][1002] = {{0}};

void allAround(int mod) {
    if (mod) {
        for (int i = 1; i < r; i += 2) {
            for (int j = 1; j < c; j++) {
                cout << "R";
            }
            cout << "D";
            for (int j = 1; j < c; j++) {
                cout << "L";
            }
            cout << "D";
        }
        for (int j = 1; j < c; j++) {
            cout << "R";
        }
    } else {
        for (int i = 1; i < c; i += 2) {
            for (int j = 1; j < r; j++) {
                cout << "D";
            }
            cout << "R";
            for (int j = 1; j < r; j++) {
                cout << "U";
            }
            cout << "R";
        }
        for (int j = 1; j < r; j++) {
            cout << "D";
        }
    }
}
void goAround(int x, int y) {
    int i = 2, j = 2;
    while (x > i) {
        for (int k = 1; k < c; k++) {
            cout << "R";
        }
        cout << "D";
        for (int k = 1; k < c; k++) {
            cout << "L";
        }
        cout << "D";
        i += 2;
    }
    while (y > j) {
        cout << "DRU";
        if (y < j) break;
        cout << "R";
        j += 2;
    }
    if (i == x) {
        cout << "RD";
    } else {
        cout << "DR";
    }
    while (j < c) {
        cout << "RURD";
        j += 2;
    }
    while (i < r) {
        cout << "D";
        for (int k = 1; k < c; k++) {
            cout << "L";
        } cout << "D";
        for (int k = 1; k < c; k++) {
            cout << "R";
        }
        i += 2;
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> land[i][j];
            if (temp > land[i][j]) {
                if ((i + j) % 2) {
                    x = i;
                    y = j;
                    temp = land[i][j];
                }
            }
        }
    }
    if (r % 2) {
        allAround(1);
    } else if (c % 2) {
        allAround(0);
    } else {
        //cout << "(" << x << ", " << y << ")\n";
        goAround(x, y);
    }
    return 0;
}