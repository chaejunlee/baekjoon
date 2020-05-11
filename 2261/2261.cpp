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
            // �� �����غ��� ���� 4�� ���� �� �����غ��� ��
            // ���� ũ��Ƽ���� ���� mid �� �ִ� ���� �ǵ�
            // mid �� �� ������ �ߺ��� ���� ���� (�ִٸ� dist == 0�� �Ŵϱ�)
            // �׷��� �̵忡������ (0, 0) (+d, 0), (0, +d)�� ���� Ȯ���ϸ� �ȴ�
            // (0, 0) �����ϸ� d = 0
            // (+d, 0) �����ϸ� d = d
            // (0, +d) �����ϸ� d = d
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