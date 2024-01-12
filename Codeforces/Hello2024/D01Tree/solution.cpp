#include <bits/stdc++.h>

using namespace std;

vector<int> a, l, r;
int n;

bool check(int x) {
	return x >= 0 && x < n && ((l[x] >= 0 && a[l[x]] == a[x] - 1) || (r[x] < n && a[r[x]] == a[x] - 1));
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		cin >> n;

		a.resize(n), l.resize(n), r.resize(n);
		vector<bool> x(n, 0);

		bool root = 0;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			l[i] = i - 1;
			r[i] = i + 1;

			if (!a[i]) {
				root = 1;
			}
		}

		priority_queue<array<int, 2>> pq;
		for (int i = 0; i < n; i++) {
			if (check(i)) {
				x[i] = 1;
				pq.push({a[i], i});
			}
		}

		while (!pq.empty()) {
			int cur = pq.top()[1];
			pq.pop();

			// delete the current one from the sequence
			if (l[cur] >= 0) {
				r[l[cur]] = r[cur];
			}

			if (r[cur] < n) {
				l[r[cur]] = l[cur];
			}

			if (check(r[cur]) && !x[r[cur]]) {
				x[r[cur]] = 1;
				pq.push({a[r[cur]], r[cur]});
			}

			if (check(l[cur]) && !x[l[cur]]) {
				x[l[cur]] = 1;
				pq.push({a[l[cur]], l[cur]});
			}
		}

		int remaining = 0;
		for (int i = 0; i < n; i++) {
			remaining += !x[i];
		}

		if (root && remaining == 1) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}

// tree must start as 1 0 or 0 1
// 0 can be replaced with 0 1 or 1 0
// 1 can be replaced with 1 2 or 2 1
