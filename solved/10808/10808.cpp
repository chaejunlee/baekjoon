#include <iostream>
#include <string>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int alphabet[26] = { 0 };
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		alphabet[s[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		cout << alphabet[i] << " ";
	}
	return 0;
}