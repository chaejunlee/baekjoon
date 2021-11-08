#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int INF = 987654321;
const int MAX = 1000000 + 1;

int N, M;
vector<int> broken;

int changeFromHundred(void) {
    return abs(N - 100);
}
bool possible(int num) {
    if (num == 0)
        if (find(broken.begin(), broken.end(), 0) == broken.end())
            return true;
        else
            return false;
    while (num) {
        if (find(broken.begin(), broken.end(), num % 10) != broken.end())
            return false;
        num /= 10;
    }
    return true;
}
int length(int num) {
    if (num == 0)
        return 1;
    int result = 0;
    while (num) {
        num /= 10;
        result++;
    }
    return result;
}
int changeEntirely(void) {
    int result = INF;
    int similar = 0;
    for (int i = 0; i < MAX; i++) {
        if (possible(i)) {
            int click = abs(N - i);
            if (result > click) {
                result = click;
                similar = i;
            }
        }
    }
    return result + length(similar);
}
int main(void) {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int button;
        cin >> button;
        broken.push_back(button);
    }
    cout << min(changeFromHundred(), changeEntirely());
    return 0;
}