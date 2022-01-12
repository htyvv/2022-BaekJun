#include <iostream>

using namespace std;

int x, y;

int main() {

	cin >> x >> y;
	if (x < 0) {
		if (y < 0) cout << 3;
		else cout << 2;
	}
	else if (y < 0){
		cout << 4;
	}
	else {
		cout << 1;
	}

	return 0;
}