#include <bits/stdc++.h>

using namespace std;

typedef int uci;
#define int long long
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

uci main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	vector<int> a(n);
	for (int& x : a) cin >> x;
	sort(all(a));
	int r = min(a[0], a[n - 1] / 2);
	cout << a[0] - r << '\n';
}
