#include <bits/stdc++.h>
using namespace std;

int dir_y[4] = {1, -1, 0, 0};
int dir_x[4] = {0, 0, 1, -1};
int N, input[20][20];
int arr[5];
int K = 5;
long long solve(int n) {
    if (n == K) {
        long long ret = 0;
        long long board[20][20];
        memset(board, -1, sizeof(board));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                board[i][j] = input[i][j];
            }
        }
        for (int k = 0; k < K; k++) {
            //cout << arr[k] << " ";
            // down
            if (arr[k] == 0) {
                for (int j = 0; j < N; j++) {
                    queue<int> q;
                    for (int i = N - 1; i >= 0; i--) {
                        if (board[i][j]) q.push(board[i][j]);
                        board[i][j] = 0;
                    }
                    int i = N - 1;
                    while (!q.empty()) {
                        int a = q.front();
                        q.pop();
                        if (board[i][j] == 0) {
                            board[i][j] = a;
                            ret = max(ret, board[i][j]);
                        }
                        else if (board[i][j] == a) {
                            board[i][j] += a;
                            ret = max(ret, board[i][j]);
                            i--;
                        }
                        else {
                            i--;
                            board[i][j] = a;
                            ret = max(ret, board[i][j]);
                        }
                    }
                }
                
            }
            // up
            if (arr[k] == 1) {
                for (int j = 0; j < N; j++) {
                    queue<int> q;
                    for (int i = 0; i < N; i++) {
                        if (board[i][j]) q.push(board[i][j]);
                        board[i][j] = 0;
                    }
                    int i = 0;
                    while (!q.empty()) {
                        int a = q.front();
                        q.pop();
                        if (board[i][j] == 0) {
                            board[i][j] = a;
                            ret = max(ret, board[i][j]);
                        }
                        else if (board[i][j] == a) {
                            board[i][j] += a;
                            ret = max(ret, board[i][j]);
                            i++;
                        }
                        else {
                            i++;
                            board[i][j] = a;
                            ret = max(ret, board[i][j]);
                        }
                    }
                }
            }
            // right
            if (arr[k] == 2) {
                for (int i = 0; i < N; i++) {
                    queue<int> q;
                    for (int j = N - 1; j >= 0; j--) {
                        if (board[i][j]) q.push(board[i][j]);
                        board[i][j] = 0;
                    }
                    int j = N - 1;
                    while (!q.empty()) {
                        int a = q.front();
                        q.pop();
                        if (board[i][j] == 0) {
                            board[i][j] = a;
                            ret = max(ret, board[i][j]);
                        }
                        else if (board[i][j] == a) {
                            board[i][j] += a;
                            ret = max(ret, board[i][j]);
                            j--;
                        }
                        else {
                            j--;
                            board[i][j] = a;
                            ret = max(ret, board[i][j]);
                        }
                    }
                }
            }
            // left
            if (arr[k] == 3) {
                for (int i = 0; i < N; i++) {
                    queue<int> q;
                    for (int j = 0; j < N; j++) {
                        if (board[i][j]) q.push(board[i][j]);
                        board[i][j] = 0;
                    }
                    int j = 0;
                    while (!q.empty()) {
                        int a = q.front();
                        q.pop();
                        if (board[i][j] == 0) {
                            board[i][j] = a;
                            ret = max(ret, board[i][j]);
                        }
                        else if (board[i][j] == a) {
                            board[i][j] += a;
                            ret = max(ret, board[i][j]);
                            j++;
                        }
                        else {
                            j++;
                            board[i][j] = a;
                            ret = max(ret, board[i][j]);
                        }
                    }
                }
            }
        }/*
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        cout << ret << "\n";
        */
        return ret;
    }
    
    long long ret = 0;
    for (int i = 0; i < 4; i++) {
        arr[n] = i;
        ret = max(ret, solve(n + 1));
    }
    return ret;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> input[i][j];
        }
    }
    cout << solve(0);
	
	return 0;
}
