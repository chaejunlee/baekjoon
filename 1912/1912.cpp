#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace chrono;

int main(void) {
	// auto start = high_resolution_clock::now();
	int n = 0, big = 0;
	int* series = NULL;
	int* dp = NULL;

	cin >> n;
	series = new int[n + 1]();
	for (int i = 1; i <= n; i++)
		cin >> series[i];
	dp = new int[n + 1] ();
	dp[1] = series[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = max(series[i], dp[i - 1] + series[i]);
	}
	big = dp[1];
	for (int i = 1; i <= n; i++) {
		if (big < dp[i])
			big = dp[i];
	}
	cout << big;

	/*auto stop = high_resolution_clock::now();
	duration<double> duration = (stop - start);
	cout << "\nTime taken: " << duration.count() << "sec" << endl;*/
	return 0;
}