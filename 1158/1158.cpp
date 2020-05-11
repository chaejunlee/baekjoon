#include <iostream>
#include <list>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0, k = 0;
	cin >> n >> k;

	list<int> series;

	for (int i = 1; i <= n; i++)
		series.push_back(i);

	auto ptr = series.begin();

	cout << '<';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k - 1; j++) {
			if (ptr == series.end()) ptr = series.begin();
			ptr++;
			if (ptr == series.end()) ptr = series.begin();
		}
		cout << *ptr;
		ptr = series.erase(ptr);
		if (i < n - 1)
			cout << ", ";
	}
	cout << '>';

	return 0;
}