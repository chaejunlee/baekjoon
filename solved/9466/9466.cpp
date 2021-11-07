#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000 + 1;

int N = 0, cnt = 0;
int student[MAX] = { 0 };
bool visited[MAX] = { false };
bool done[MAX] = { false };

void DFS(int from) {
    visited[from] = true;

    int to = student[from];
    // finding cycle in the graph
    if (!visited[to])
        DFS(to);
    // If it already visited "to"
    // then the graph has a cycle containing "to".
    // Therefore cycling through "to" back to itself can find the team member. 
    else if (!done[to]) {
        for (int i = to; i != from; i = student[i])
            cnt++;
        cnt++;
    }
    done[from] = true;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 0, input = 0;
    cin >> T;
    while (T--) {
        cnt = 0;
        cin >> N;
        fill(visited, visited + N + 1, false);
        fill(done, done + N + 1, false);
        for (int i = 1; i <= N; i++) {
            cin >> input;
            student[i] = input;
        }

        for (int i = 1; i <= N; i++)
            if (!done[i])
                DFS(i);

        cout << N - cnt << "\n";
    }
    return 0;
}