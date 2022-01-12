#include<iostream>
#include<deque>

using namespace std;

int t[9][9];  // ������ ���̺�
int n;  // ������ ���̺��� ��ĭ ��
deque<pair<int, int>> p;  // ������ ���̺��� ��ĭ ��ǥ
bool isEnd = false;

bool check(int depth) {
	int x = p[depth].first;
	int y = p[depth].second;
	int x_square = x / 3;
	int y_square = y / 3;
	// ���� �� Ȯ��
	for (int i = 0; i < 9; i++) {
		if (i != y && t[x][i] == t[x][y]) return false; 
	}
	// ���� �� Ȯ��
	for (int i = 0; i < 9; i++) {
		if (i != x && t[i][y] == t[x][y]) return false;
	}
	// ���� ĭ Ȯ��
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (!(x_square * 3 + i == x && y_square * 3 + j == y) && t[x_square * 3 + i][y_square * 3 + j] == t[x][y]) 
				return false;
		}
	}
	return true;
}

void backtracking(int depth) {

	// ���� ����(��� ��ĭ�� ä���� ��)
	if (depth == n) {
		// ��� ���
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << t[i][j] << " ";
			}
			cout << "\n";
		}
		isEnd = true;
		return;
	}

	for (int i = 1; i <= 9; i++) {
		t[p[depth].first][p[depth].second] = i;
		if (check(depth)) {
			backtracking(depth + 1);
		}
		if (isEnd) return;
	}
	t[p[depth].first][p[depth].second] = 0;
	return;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// ������ ���̺� �Է� �����鼭 ������ ��ĭ ��ġ deque�� �����صα�
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> t[i][j];
			if (t[i][j] == 0) p.push_back(make_pair(i, j));
		}
	}

	// �������� ��ĭ ���� ����
	n = p.size();

	// ������ ���� Ǯ��
	backtracking(0);

	return 0;
}