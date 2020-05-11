#include <iostream>
#include <cstring>
using namespace std;

int N;
char star[][6] = {"  *  ", " * * ", "*****"};
char board[3073][6145] = {" "};

void makeBoard(int n, int x, int y) {
    if (n / 3 == 1) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 5; j++) {
                board[x + i][y + j] = star[i][j];
            }
        }
        return;
    }
    makeBoard(n / 2, x, y + n / 2);
    makeBoard(n / 2, x + n / 2, y);
    makeBoard(n / 2, x + n / 2, y + n);
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(board, ' ', sizeof(board));
    cin >> N;
    makeBoard(N, 0, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2 * N + 1; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
    return 0;
}
/*
*
*_*
*****
*_____*
*_*___*_*
*****_*****
*/