#include <bits/stdc++.h>
#include <bits/debug.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> l(n + 1), r(n);
		l[n] = INT_MAX;

		vector<array<int, 2>> segments;

		for (int i = 0; i < n; i++) {
			cin >> l[i];
		}

		int match = 0;
		int total = 0;
		for (int i = 0; i < n; i++) {
			cin >> r[i];

			if (r[i] + 1 != l[i]) {
				segments.push_back({l[match], r[i]});
				total += r[i] - l[match] + 1;
				match = i + 1;
			}
		}

		if (k > total) {
			cout << -1 << '\n';
			continue;
		}

		debug(segments);
	}
}
