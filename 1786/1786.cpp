#include <bits/stdc++.h>
using namespace std;

string T, P;

vector<int> getPartialMatch(const string& N) {
    int m = N.size();
    vector<int> pi(m, 0);

    int begin = 1, matched = 0;

    while (begin + matched < m) {
        if (N[begin + matched] == N[matched]) {
            ++matched;
            pi[begin + matched - 1] = matched;
        }
        else {
            if (matched == 0) ++begin;
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }

    return pi;
}

vector<int> kmpSearch(const string& H, const string& N) {
    int n = H.size(), m = N.size();
    vector<int> ret;

    vector<int> pi = getPartialMatch(N);

    int begin = 0, matched = 0;

    while (begin <= n - m) {
        if (matched < m && H[begin + matched] == N[matched]) {
            ++matched;
            if (matched == m) ret.push_back(begin);
        }
        else {
            if (matched == 0) begin++;
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return ret;
}


int main(void) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    getline(cin, T);
    getline(cin, P);
    //cout << T << "\n" << P <<"\n";

    vector<int> N = kmpSearch(T, P);
    
    cout << N.size() << "\n";
    for (auto i : N) cout << i + 1 << " ";
    cout << "\n";

    return 0;
}