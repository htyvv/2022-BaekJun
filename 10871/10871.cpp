#include <iostream>

using namespace std;

int n, x;
int num;

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> x;

	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num < x) cout << num << " ";
	}

	return 0;
}