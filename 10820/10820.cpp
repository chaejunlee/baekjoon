#include <iostream>
#include <string>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	int check[4] = { 0 }, n = 0;

	while (getline(cin, s)) {
		fill_n(check, 4, 0);
		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= 'a' && s[i] <= 'z')
				check[0]++;
			else if (s[i] >= 'A' && s[i] <= 'Z')
				check[1]++;
			else if (s[i] >= '0' && s[i] <= '9')
				check[2]++;
			else if (s[i] == ' ')
				check[3]++;
		}
		for (int j = 0; j < 4; j++)
			cout << check[j] << " ";
		cout << "\n";
	}
	return 0;
}