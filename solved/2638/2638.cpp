#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[101][101];
int cnt[101][101];
int visited[101][101];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int solve() {
    int ret = 0;
    queue<pair<int, int> > q;
    int y, x;
    while (true) {
        queue<pair<int, int> > p;
        p.push({0,0});
        memset(cnt, 0, sizeof(cnt));
        memset(visited, 0, sizeof(visited));
        
        while (!p.empty()) {
            y = p.front().first;
            x = p.front().second;
            p.pop();
            
            for (int k = 0; k < 4; k++) {
                int dy = y + dir[k][0];
                int dx = x + dir[k][1];
                if (dy >= 0 && dy < N && dx >= 0 && dx < M) {
                    if (board[dy][dx]) {
                        cnt[dy][dx] += 1;
                    }
                    else {
                        if (!visited[dy][dx]) {
                            p.push({dy,dx});
                            visited[dy][dx] = 1;
                        }
                    }
                }
            }
        }
        
        int check = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                //cout << board[i][j] << " ";
                if (cnt[i][j] >= 2) {
                    board[i][j] = 0;
                }
                if (cnt[i][j]) check = 1;
            }
            //cout << "\n";
        }
        //cout << "\n";
        
        if (check == 0) {
            return ret;
        }
        ret++;
    }
}


int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    
    cout << solve() << "\n";
    
    return 0;
}
