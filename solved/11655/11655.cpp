#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		int rot = 0;
		if (s[i] >= 'A' && s[i] <= 'Z') {
			rot = s[i] + 13;
			if (rot > 'Z')
				s[i] = (rot - 'Z') + 'A' - 1;
			else s[i] = rot;
		}
		if (s[i] >= 'a' && s[i] <= 'z') {
			rot = s[i] + 13;
			if (rot > 'z')
				s[i] = (rot - 'z') + 'a' - 1;
			else s[i] = rot;
		}
	}
	cout << s;
	return 0;
}