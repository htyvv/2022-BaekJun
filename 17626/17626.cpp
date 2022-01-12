#include <iostream>
#include <vector>

using namespace std;

int n;
int res = 1; // Á¦°ö¼ö °³¼ö
vector<int> nums;
bool isFound;

void permu(int depth) {
	if (depth == res) {
		int sum = 0;
		for (auto a : nums) sum += a * a;
		
		if (sum == n) {
			//for (auto a : nums) cout << a << " ";
			//cout << endl;
			//cout << "@ n = " << n << ",   res = " << res << ",   sum = " << sum << endl; // debug line
			isFound = true;
		} 
		return;
	}
	for (int i = 1; i * i <= n; i++) {
		nums.push_back(i);
		permu(depth + 1);
		if (isFound) return;
		nums.pop_back();
	}
}

int main() {
	cin >> n;
	while (res) {
		if (isFound) break;
		permu(0);
		res++;
	}
	cout << res - 1;
}