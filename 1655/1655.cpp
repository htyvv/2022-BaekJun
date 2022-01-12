#include<iostream>
#include<queue>

using namespace std;

int n;
priority_queue<int, vector<int>> maxheap;
priority_queue<int, vector<int>, greater<int>> minheap;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {

		int input = -1; cin >> input;  // ���� �Է� �ޱ�

		if (maxheap.size() == 0) {
			maxheap.push(input);  // �ʱ⿡�� �ִ����� ����
		}
		else {
			if (maxheap.size() > minheap.size()) {
				minheap.push(input);
			}
			else {
				maxheap.push(input);
			}

			int maxtop = maxheap.top();
			int mintop = minheap.top();
			if (maxtop > mintop) {
				maxheap.pop();
				minheap.pop();
				maxheap.push(mintop);
				minheap.push(maxtop);

			}	
		}
		cout << maxheap.top() << "\n";
	}

	return 0;
}