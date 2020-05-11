#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	char buffer = NULL;
	int n = 0, top = 0;
	string input;
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> input;
		stack<int> s;
		for (int i = 0; i < input.size(); i++) {
			if (s.empty()) {
				if (input[i] == ')') {
					s.push(-1);
					break;
				}
			}
			if (input[i] == '(') {
				s.push(1);
			}
			else if (input[i] == ')') {
				s.pop();
			}
		}
		if (s.empty())
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	return 0;
}