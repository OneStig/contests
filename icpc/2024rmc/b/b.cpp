#include <bits/stdc++.h>

using namespace std;

typedef int uci;
#define int long long
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

uci main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n / 2), b((n + 1) / 2);

	for (int& x : a) cin >> x;
	for (int& x : b) cin >> x;

	int found = -1;
	unordered_set<int> seenSums;
	vector<int> as, bs;
	as.reserve(1ll << sz(a));
	bs.reserve(1ll << sz(b));

	for (int mask = 1; mask < (1ll << sz(a)); mask++) {
		int curSum = 0;
		for (int i = 0; i < sz(a); i++) {
			if (mask & (1ll << i)) {
				curSum += a[i];
			}
		}

		if (seenSums.find(curSum) != seenSums.end()) {
			found = curSum;
			break;
		}

		seenSums.insert(curSum);
		as.push_back(curSum);
	}

	for (int mask = 1; mask < (1ll << sz(b)); mask++) {
		int curSum = 0;
		for (int i = 0; i < sz(b); i++) {
			if (mask & (1ll << i)) {
				curSum += b[i];
			}
		}

		if (seenSums.find(curSum) != seenSums.end()) {
			found = curSum;
			break;
		}


		if (seenSums.find(curSum) != seenSums.end()) {
			found = curSum;
			break;
		}

		seenSums.insert(curSum);
		bs.push_back(curSum);
	}

	as.push_back(0);
	sort(all(as));
	sort(all(bs));

	if (found != -1) {
		cout << found << '\n';
		return 0;
	}

	// binary search on range to find answer
	int inleft = 0;
	int l = 1, r = (1ll << n) - 2;
	while (l != r) {
		int mid = (l + r) / 2;
		// count for range [l, mid] if not extra then (mid, r]
		int count = 0;
		int bi = sz(bs) - 1;
		for (int ai = 0; ai < sz(as); ai++) {
			while (bi >= 0 && as[ai] + bs[bi] > mid) {
				bi--;
			}

			count += bi + 1;
			if (ai != 0 && as[ai] <= mid) {
				count++;
			}

			if (as[ai] > mid) break;
		}

		count -= inleft;

		if (count > mid - l + 1) {
			r = mid;
		}
		else {
			l = mid + 1;
			inleft += count;
		}
	}

	cout << l << '\n';
}
