#include <iostream>

using namespace std;

int t;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	for (int i = 1; i <= t; i++) {

		for (int k = 0; k < t-i; k++) {
			cout << " ";
		}

		for (int j = 0; j < i; j++) {
			cout << "*";
		}

		cout << "\n";
	}
	return 0;
}