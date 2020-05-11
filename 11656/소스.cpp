#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	string s;
	string temp[1000];

	cin >> s;
	int last = s.length();

	for (int i = 0; i < last; i++) {
		temp[i] = s.substr(i, last);
	}
	sort(temp, temp + last);

	for (int i = 0; i < last; i++) {
		cout << temp[i] << "\n";
	}
	return 0;
}