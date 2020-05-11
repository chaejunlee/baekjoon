#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	a += b;
	c += d;
	cout << stoll(a.c_str()) + stoll(c.c_str());
	return 0;
}