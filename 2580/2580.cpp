#include<iostream>
#include<deque>

using namespace std;

int t[9][9];  // 스도쿠 테이블
int n;  // 스도쿠 테이블의 빈칸 수
deque<pair<int, int>> p;  // 스도쿠 테이블의 빈칸 좌표
bool isEnd = false;

bool check(int depth) {
	int x = p[depth].first;
	int y = p[depth].second;
	int x_square = x / 3;
	int y_square = y / 3;
	// 같은 행 확인
	for (int i = 0; i < 9; i++) {
		if (i != y && t[x][i] == t[x][y]) return false; 
	}
	// 같은 열 확인
	for (int i = 0; i < 9; i++) {
		if (i != x && t[i][y] == t[x][y]) return false;
	}
	// 같은 칸 확인
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (!(x_square * 3 + i == x && y_square * 3 + j == y) && t[x_square * 3 + i][y_square * 3 + j] == t[x][y]) 
				return false;
		}
	}
	return true;
}

void backtracking(int depth) {

	// 종료 조건(모든 빈칸을 채웠을 때)
	if (depth == n) {
		// 결과 출력
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

	// 스도쿠 테이블 입력 받으면서 스도쿠 빈칸 위치 deque에 저장해두기
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> t[i][j];
			if (t[i][j] == 0) p.push_back(make_pair(i, j));
		}
	}

	// 스도쿠의 빈칸 개수 저장
	n = p.size();

	// 스도쿠 문제 풀이
	backtracking(0);

	return 0;
}