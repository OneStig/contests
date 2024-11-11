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
	int a = 0;
	int b = 300000;
	for (int i = 0; i < n; i++) {
		int x,y;
		cin >> x >> y;
		a = max(x,a);
		b = min(y,b);
	}
	if (b < a) {
		cout << "bad news\n";
	}
	else {
		cout << b - a + 1 << " " << a << "\n";
	}
}
