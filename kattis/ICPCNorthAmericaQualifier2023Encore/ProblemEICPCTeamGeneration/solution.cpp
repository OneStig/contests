#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<array<int, 2>> r(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> r[i][0] >> r[i][1];
	}

	int teams = 0;

	for (int i = 1; i <= n - 2; i++) {
		if (r[i][1] >= i + 2 && r[i + 2][0] <= i) {
			teams++;
			i += 2;
		}
	}

	cout << teams << endl;
}
