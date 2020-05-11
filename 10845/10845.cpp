#include <iostream>
#include <string>
using namespace std;

int queue[10001] = { 0 };
int front = 0, rear = 0;
int qSize = 0;

void push(int x) {
	queue[rear++] = x;
	qSize++;
}

int pop(void) {
	if (front == rear)
		return -1;
	qSize--;
	return queue[front++];
}

int qEmpty(void) {
	if (front == rear)
		return 1;
	return 0;
}

int qFront(void) {
	if (front == rear)
		return -1;
	return queue[front];
}

int qBack(void) {
	if (front == rear)
		return -1;
	return queue[rear - 1];
}

int main(void) {
	ios_base::sync_with_stdio(false);

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
			cout << pop() << '\n';
		}
		else if (!input.compare("empty")) {
			cout << qEmpty() << '\n';
		}
		else if (!input.compare("size")) {
			cout << rear - front << '\n';
		}
		else if (!input.compare("front")) {
			cout << qFront() << '\n';
		}
		else if (!input.compare("back")) {
			cout << qBack() << '\n';
		}
	}
	
	return 0;
}