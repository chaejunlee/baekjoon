#include <iostream>
using namespace std;

int N;

void printStar(int i, int j) {
    if (i % 3 == 1 && j % 3 == 1) {
        cout << " ";
    } else if (i > 2 || j > 2) {
        printStar(i / 3, j / 3);
    } else {
        cout << "*";
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printStar(i, j);
        }
        cout << "\n";
    }
    return 0;
}
/*
1 4 7 -> i%3 == 1 || j%3 == 1
3 4 5 12 13 14 -> (i / 3) % 3 == 1 || (j / 3) % 3
9 10 11 12 13 14 15 16 17
*/