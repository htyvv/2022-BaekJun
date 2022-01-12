#include <iostream>

using namespace std;

int dp[101][100001];
int w[101];
int v[101];

int knapsack(int n, int k) {
	if (n == 0 || k == 0) return 0;  // �ʱ� ��
	if (dp[n][k] != 0) return dp[n][k];  // �޸������̼ǵǾ� ������ ���
	if (k - w[n] >= 0) return dp[n][k] = max(knapsack(n - 1, k - w[n]) + v[n], knapsack(n - 1, k));  // n��° ������ ���ʿ� ���濡 ���� �� �ִ� �� ���� �� �Ǵ�
	else return dp[n][k] = knapsack(n - 1, k);  // ���ʿ� ���� �� ���ٸ� max �ʿ���� �ٷ� n��° ������ �������� ���ϴ� subproblem
}

int main() {
	int n=0; int k=0; 
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
	cout << knapsack(n, k);
	return 0;
}