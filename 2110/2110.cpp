#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C;
vector<long long> house;
long long lastHouse = 0, firstHouse = 987654321;
long long idealDist;
long long ans;

bool isPossibleDist(long long dist) {
    long long cnt = 1;
    long long router = house[0];
    for (int i = 1; i < N; i++)
        if (house[i] - router >= dist) {
            cnt++;
            router = house[i];
        }
    return cnt >= C;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C;
    long long temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        house.push_back(temp);
        lastHouse = max(lastHouse, temp);
        firstHouse = min(firstHouse, temp);
    }
    sort(house.begin(), house.end());
    long long low = 1, high = 1000000000;
    while (low < high) {
        long long middle = (high + low) / 2;
        if (isPossibleDist(middle))
            low = middle + 1;
        else
            high = middle - 1;
        cout << "high: " << high << " low: " << low << "\n";
    }
    cout << low;

    return 0;
}