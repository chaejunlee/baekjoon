// 구현이 엄청 어려운 문제였다.. 답을 봐버렸음..

#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[11][11];
int visited[11][11][11][11];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int s_by, s_bx, s_ry, s_rx, oy, ox;

struct balls {
    int depth;
    int ry, rx, by, bx;
};

void move(int& y, int& x, int i) {
    while (1) {
        y += dir[i][0]; x += dir[i][1];
        if (board[y][x] == 1) {
            y -= dir[i][0]; x -= dir[i][1];
            break;
        }
        else if (y == oy && x == ox) {
            break;
        }
    }
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
	    string s;
	    cin >> s;
		for (int j = 0; j < M; j++) {
		    char temp = s[j];
		    if (temp == 'B') {
		        s_by = i;
		        s_bx = j;
		    }
		    if (temp == 'R') {
		        s_ry = i;
		        s_rx = j;
		    }
		    if (temp == 'O') {
		        oy = i;
		        ox = j;
		    }
		    if (temp == '.') {
		        board[i][j] = 0;
		    }
		    if (temp == '#') {
		        board[i][j] = 1;
		    }
		}
	}
	
	queue<balls> q;
	q.push({0, s_ry, s_rx, s_by, s_bx});
	visited[s_ry][s_rx][s_by][s_bx] = 1;
	int ret = -1;
	while (!q.empty()) {
	    balls cur = q.front();
	    q.pop();
	    // cout << cur.depth << " " << cur.ry << " " << cur.rx << " " << cur.by << " " << cur.bx << "\n";
	    
	    if (cur.depth > 10) break;
	    if (cur.ry == oy && cur.rx == ox) {
	        ret = cur.depth; break;
	    }
	    
	    for (int i = 0; i < 4; i++) {
	        int d_ry = cur.ry, d_rx = cur.rx;
	        int d_by = cur.by, d_bx = cur.bx;
	        move(d_ry, d_rx, i); move(d_by, d_bx, i);
	        
	        if (d_by == oy && d_bx == ox) continue;
	        
	        if (d_ry == d_by && d_rx == d_bx) {
	            if (i == 0) {
	                cur.ry < cur.by ? d_ry-- : d_by--;
	            }
	            if (i == 1) {
	                cur.rx < cur.bx ? d_rx-- : d_bx--;
	            }
	            if (i == 2) {
	                cur.ry < cur.by ? d_by++ : d_ry++;
	            }
	            if (i == 3) {
	                cur.rx < cur.bx ? d_bx++ : d_rx++;
	            }
	        }
	        
	        if (!visited[d_ry][d_rx][d_by][d_bx]) {
	            balls next;
	            next.depth = cur.depth + 1;
	            next.ry = d_ry; next.rx = d_rx;
	            next.by = d_by; next.bx = d_bx;
	            q.push(next);
	            visited[d_ry][d_rx][d_by][d_bx] = 1;
	        }
	    }
	}
	
	cout << ret << "\n";

	return 0;
}
