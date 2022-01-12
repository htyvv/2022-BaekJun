#include <iostream>
#include <string>
using namespace std;
int main(void) {
	int n, m;
	cin >> n >> m;
	string dna[1000];
	int alphabet[26];
	string s = "";
	int cnt = 0;
	for (int i = 0; i < n; i++) cin >> dna[i];
	for (int i = 0; i < m; i++) {
		int max = 0;
		fill_n(alphabet, 26, 0);
		for (int j = 0; j < n; j++) {
			int idx = dna[j][i] - 65;
			alphabet[idx]++;
			if (max < alphabet[idx]) max = alphabet[idx];
		}
		for (int j = 0; j < 26; j++) {
			if (alphabet[j] == max) {
				s += (char)(j + 65);
				break;
			}
		}
		for (int j = 0; j < n; j++)
			if (s[i] != dna[j][i]) cnt++;
	}
	cout << s << '\n' << cnt;
	return 0;
}