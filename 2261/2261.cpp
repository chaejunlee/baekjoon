#include <iostream>
#include <algorithm>
#include <vector>
#define X first
#define Y second
#define MAX 1000000000000ll
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PAIR;
PAIR point[500000];
int n;

LL square(LL a) {
    return a * a;
}
LL dist(PAIR a, PAIR b) {
    return square(a.X - b.X) + square(a.Y - b.Y);
}
bool cmp(PAIR a, PAIR b) {
    if (a.Y != b.Y)
        return a.Y < b.Y;
    else
        return a.X < b.X;
}
LL solve(PAIR* point, int start, int end) {
    if (end - start == 1)
        return MAX;
    int mid = (start + end) / 2;
    LL d = min(solve(point, start, mid), solve(point, mid, end));
    vector<PAIR> V;
    LL seperator = point[mid].X;
    for (int i = start; i < end; i++) {
        if (square(point[i].X - seperator) < d)
            V.push_back(point[i]);
    }
    sort(V.begin(), V.end(), cmp);
    for (int i = 0; i < V.size(); i++) {
        for (int j = i + 1; j < V.size() && j < i + 5; j++) {
            // 잘 생각해보면 앞의 4개 점만 더 생각해보면 됨
            // 가장 크리티컬한 점은 mid 상에 있는 점일 건데
            // mid 양 옆 구역에 중복된 점은 없다 (있다면 dist == 0일 거니까)
            // 그래서 미드에서부터 (0, 0) (+d, 0), (0, +d)인 점만 확인하면 된다
            // (0, 0) 존재하면 d = 0
            // (+d, 0) 존재하면 d = d
            // (0, +d) 존재하면 d = d
            d = min(d, dist(V[i], V[j]));
        }
    }
    return d;
}
int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> point[i].X >> point[i].Y;
    sort(point, point + n);
    cout << solve(point, 0, n);
}