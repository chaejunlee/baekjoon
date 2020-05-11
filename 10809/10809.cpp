#include <iostream>
#include <string>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	char alphabet[26] = { 0 };

	cin >> s;
	fill_n(alphabet, 26, -1);
	for (int i = 0; i < s.size(); i++) {
		if (alphabet[s[i] - 'a'] == -1) {
			alphabet[s[i] - 'a'] = i;
		}
	}
	
	for (int i : alphabet) {
		cout << i << " ";
	}
	return 0;
}