#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> PAIR;

int n = 0;
vector<PAIR> v;

bool cmp(PAIR a, PAIR b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(b, a));
    }
    sort(v.begin(), v.end(), cmp);
    for (auto i : v) {
        cout << i.first << " " << i.second << "\n";
    }

    int cnt = 0;
    int end = 0;
    for (int i = 0; i < v.size(); i++) {
        if (end <= v[i].second) {
            end = v[i].first;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}

/*
11
0 6
1 4
2 13
3 5
3 8
5 7
5 9
6 10
8 11
8 12
12 14
*/