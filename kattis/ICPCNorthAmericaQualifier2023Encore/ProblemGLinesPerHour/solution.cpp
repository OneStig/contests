#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, lines;
	cin >> n >> lines;
	lines *= 5;

	vector<int> probs(n);

	for (int& i : probs) {
		cin >> i;
	}

	sort(probs.begin(), probs.end());

	int ans = 0;

	for (int i = 0; i < n; i++) {
		if (probs[i] > lines) {
			break;
		}
		ans++;
		lines -= probs[i];
	}

	cout << ans << endl;
}
