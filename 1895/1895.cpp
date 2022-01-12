#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int R, C, T;
int img[40][40];

int dx[] = {-1,0,1,1,1,0,-1,-1,0};
int dy[] = {-1,-1,-1,0,1,1,1,0,0};

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> img[i][j];
		}
	}
	cin >> T;

	int cnt = 0;
	for (int i = 1; i < R-1; i++) {
		for (int j = 1; j < C-1; j++) {
			vector<int> v;
			for (int k = 0; k < 9; k++) {
				v.push_back(img[i + dy[k]][j + dx[k]]);
			}
			sort(v.begin(), v.end());
			if (v[4] >= T) cnt++;
		}
	}
	cout << cnt;
}