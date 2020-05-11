#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n, b;
char a;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        multiset<int> _map;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            if (a == 'I') {
                _map.insert(b);
            } else {
                if (_map.size() && b == -1)
                    _map.erase(_map.begin());
                else if (_map.size() && b == 1) {
                    auto it = _map.end();
                    it--;
                    _map.erase(it);
                }
            }
        }
        if (_map.empty())
            cout << "EMPTY"
                 << "\n";
        else {
            auto end_it = _map.end();
            end_it--;
            cout << (*end_it) << " " << (*_map.begin()) << "\n";
        }
    }
    return 0;
}