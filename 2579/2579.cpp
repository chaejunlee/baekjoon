#include <iostream>

using namespace std;

int stepCount[301] = { 0 }, stair[301] = { 0 };

int max(int n, int m) {
	if (n > m)
		return n;
	return m;
}

void getSteps(int n) {
	stepCount[1] = stair[1];
	stepCount[2] = max(stair[2] + stair[1], stair[2]);
	stepCount[3] = max(stair[1] + stair[3], stair[2] + stair[3]);
	for (int i = 4; i <= n; i++) {
		stepCount[i] = max(stepCount[i - 2] + stair[i], stepCount[i - 3] + stair[i] + stair[i - 1]);
	}
}

int main(void) {
	int count = 0;
	cin >> count;
	for (int i = 1; i <= count; i++)
		cin >> stair[i];
	getSteps(count);
	cout << stepCount[count];

	return 0;
}