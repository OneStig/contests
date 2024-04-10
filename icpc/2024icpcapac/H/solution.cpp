#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int ans = 0;
	vector<int> one(n);
	vector<int> zero(n);

	int minorO = 0;
	int minorZ = 0;

	int mz = INT_MAX;
	int mzi = -1;

	int mo = INT_MAX;
	int moi = -1;

	int osum = 0;
	int zsum = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (char c : s) {
			one[i] += c == '1';
			zero[i] += c == '0';
		}

		ans += min(one[i], zero[i]);

		if (one[i] < zero[i]) {
			minorO++;
		}

		if (zero[i] < one[i]) {
			minorZ++;
		}

		if (zero[i] - one[i] < mz) {
			mz = zero[i] - one[i];
			mzi = i;
		}

		if (one[i] - zero[i] < mo) {
			mo = one[i] - zero[i];
			moi = i;
		}

		osum += one[i];
		zsum += zero[i];
	}

	if (osum != 0 && zsum != 0) {
		if (minorO == n) {
			ans -= one[mzi];
			ans += zero[mzi];
		}
		else if (minorZ == n) {
			ans -= zero[moi];
			ans += one[moi];
		}
	}

	cout << ans << '\n';
}
