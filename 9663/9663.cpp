#include <iostream>
# define MAX 15

using namespace std;

int n;
int cnt;

int table[MAX];

bool isValid(int row) {
	for (int i = 0; i < row; i++) {
		if (table[i] == table[row]) return false;
		if (abs(i - row) == abs(table[i] - table[row])) return false;
	}
	return true;
}

void go(int row) {
	if (row == n) {
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++) {
		table[row] = i;
		if (isValid(row)) go(row + 1);
	}
}

int main() {
	cin >> n;
	go(0);
	cout << cnt;
	return 0;
}