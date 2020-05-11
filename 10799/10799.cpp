#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string input;
	stack<char> stk;
	char before = '\0';
	int result = 0;
	
	cin >> input;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '(') {
			stk.push(input[i]);
		}
		else if (input[i] == ')') {
			stk.pop();

			if (before == '(')
				result += stk.size();
			else
				result += 1;
		}
		before = input[i];
	}
	cout << result;
	return 0;
}