#include <iostream>

using namespace std;

int dp[101][100001];
int w[101];
int v[101];

int knapsack(int n, int k) {
	if (n == 0 || k == 0) return 0;  // 초기 값
	if (dp[n][k] != 0) return dp[n][k];  // 메모이제이션되어 있으면 사용
	if (k - w[n] >= 0) return dp[n][k] = max(knapsack(n - 1, k - w[n]) + v[n], knapsack(n - 1, k));  // n번째 물건을 애초에 가방에 넣을 수 있는 지 없는 지 판단
	else return dp[n][k] = knapsack(n - 1, k);  // 애초에 넣을 수 없다면 max 필요없이 바로 n번째 물건을 포함하지 못하는 subproblem
}

int main() {
	int n=0; int k=0; 
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
	cout << knapsack(n, k);
	return 0;
}