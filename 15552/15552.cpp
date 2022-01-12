#include <iostream>

using namespace std;

int a, b, t;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> a >> b;
		cout << a + b << "\n";
	}
}