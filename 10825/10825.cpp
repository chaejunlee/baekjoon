#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef struct student {
	string name;
	int korean;
	int english;
	int math;
} student;

int n = 0;
student ary[100000] = { { "", 0, 0, 0} };

bool cmp(student a, student b) {
	if (a.korean > b.korean)
		return true;
	else if (a.korean == b.korean) {
		if (a.english < b.english)
			return true;
		else if (a.english == b.english) {
			if (a.math > b.math)
				return true;
			else if (a.math == b.math) {
				if (a.name.compare(b.name) < 0)
					return true;
			}
		}
	}
	return false;
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> ary[i].name >> ary[i].korean >> ary[i].english >> ary[i].math;
	sort(ary, ary + n, cmp);
	for (int i = 0; i < n; i++)
		cout << ary[i].name << "\n";
	return 0;
}