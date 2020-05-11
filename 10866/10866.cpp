#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	deque<int> dq;
	int n = 0, x = 0;
	string input;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (!input.compare("push_front")) {
			cin >> x;
			dq.push_front(x);
		}
		else if (!input.compare("push_back")) {
			cin >> x;
			dq.push_back(x);
		}
		else if (!input.compare("pop_front")) {
			if (!(dq.empty())) {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
			else
				cout << -1 << '\n';
		}
		else if (!input.compare("pop_back")) {
			if (!(dq.empty())) {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
			else
				cout << -1 << '\n';
		}
		else if (!input.compare("size")) {
			cout << dq.size() << '\n';
		}
		else if (!input.compare("empty")) {
			if (dq.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (!input.compare("front")) {
			if (!dq.empty())
				cout << dq.front() << '\n';
			else
				cout << -1 << '\n';
		}
		else if (!input.compare("back")) {
			if (!dq.empty())
				cout << dq.back() << '\n';
			else
				cout << -1 << '\n';
		}
	}
	return 0;
}