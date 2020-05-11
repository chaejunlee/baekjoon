#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> NCards;
vector<pair<int, int>> MCards;
int exists[500000] = {0};

void binsearch(int target) {
    int low = 0, high = M - 1;
    while (low <= high) {
        int middle = (low + high) / 2;
        //cout << "middle: " << middle << " target: " << target << "\n";
        // for (int i = 0; i < M; i++) {
        //     cout << exists[i] << " ";
        // }
        // cout << "\n";
        if (target == MCards[middle].first) {
            exists[MCards[middle].second] = 1;
            break;
        } else if (target > MCards[middle].first)
            low = middle + 1;
        else
            high = middle - 1;
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int temp = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        NCards.push_back(temp);
    }
    sort(NCards.begin(), NCards.end());
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        MCards.push_back(make_pair(temp, i));
    }
    sort(MCards.begin(), MCards.end());
    for (int i = 0; i < N; i++) {
        binsearch(NCards[i]);
    }
    for (int i = 0; i < M; i++) {
        cout << exists[i] << " ";
    }
}