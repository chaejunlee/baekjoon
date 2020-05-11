#include <iostream>
#include <string>
using namespace std;

long int stack[10001] = { 0 };
int top = 0;

int push(int x) {
	stack[++top] = x;
	return stack[top];
}

int pop(void) {
	if (top > 0) {
		return stack[top--];
	}
	return -1;
}

int sEmpty(void) {
	if (top > 0)
		return 0;
	return 1;
}

int sTop(void) {
	if (top > 0)
		return stack[top];
	return -1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0, x = 0;
	string input;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (!input.compare("push")) {
			cin >> x;
			push(x);
		}
		else if (!input.compare("pop")) {
			cout << pop() << "\n";
		}
		else if (!input.compare("top")) {
			cout << sTop() << "\n";
		}
		else if (!input.compare("size")) {
			cout << top << "\n";
		}
		else if (!input.compare("empty")) {
			cout << sEmpty() << "\n";
		}
	}
	return 0;
}