#include <iostream>
#include <vector>
#include <algorithm>
#define NUM first
#define EXIST second
using namespace std;

int N, M;
vector<int> Cards;
vector<int> myCards;
// int exists[500000] = {0};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int temp;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        Cards.push_back(temp);
    }
    sort(Cards.begin(), Cards.end());
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        cout << upper_bound(Cards.begin(), Cards.end(), temp) - lower_bound(Cards.begin(), Cards.end(), temp) << " ";
    }
    return 0;
}