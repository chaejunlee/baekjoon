#include <iostream>
#include <string>
#include <list>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	string s;

	cin >> s;
	cin >> n;

	list<char> editor(s.begin(), s.end());
	auto cursor = editor.end();

	for (int i = 0; i < n; i++) {
		char cmd;
		cin >> cmd;

		if (cmd == 'L') {
			if (cursor != editor.begin())
				cursor--;
		}
		else if (cmd == 'D') {
			if (cursor != editor.end())
				cursor++;
		}
		else if (cmd == 'B') {
			if (cursor != editor.begin()) {
				cursor--;
				cursor = editor.erase(cursor);
			}
		}
		else {
			char x;
			cin >> x;
			editor.insert(cursor, x);
		}
	}
	for (char i : editor) {
		cout << i;
	}
}