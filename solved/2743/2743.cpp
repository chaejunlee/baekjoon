#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	char input[101] = "";
	int i = 0;

	cin >> input;

	while (input[i] != '\0') {
		i++;
	}

	cout << i;

	return 0;
}