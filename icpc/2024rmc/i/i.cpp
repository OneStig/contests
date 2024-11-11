#include <bits/stdc++.h>

using namespace std;

typedef int uci;
#define int long long
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

uci main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int w,h,n;
	cin >> w >> h >> n;
	vector<int> types;
	for (int i = 0; i < n; i++){
		int k;
		cin >> k;
		types.push_back(k);
	}
	int a = w;
	int b = h;
	int one = 1;
	int ans = 0;
	bool good = true;
	for (int bit = 0; bit < 50; bit++) {
		bool abit =  (a & (one << bit)) > 0;
		bool bbit =  (b & (one << bit)) > 0;
		int area = 0;
		if (abit) {
			area += (one << bit) * b;
		}
		if (bbit) {
			area += (one << bit) * a;
		}
		if (abit and bbit) {
			area -= (one << bit) * (one << bit);
		}
		//cout << area << " " <<a << " " << b  << " " << ans << "\n";
		//cout << area << " " << abit << " " << bbit << " " << a << " " << b << "\n";
		for (int square = bit; square > -1; square --) {
			int sa = (one << square)* (one << square);
			if (area / sa > types[square]) {
				area -= sa * types[square];
				ans += types[square];
				types[square] = 0;
			}
			else {
				int c = area/sa;
				area -= sa * c;
				ans += c;
				types[square] -= c;
			}
		}
		if (area != 0) {
			good = false;
			break;
		}
		if (abit) {
			a = a ^ (one << bit);
		}
		if (bbit) {
			b = b ^ (one << bit);
		}
	}
	if (!good) {
		cout << "-1\n";
		return 0;
	}
	cout << ans << "\n";
	return 0;
}
