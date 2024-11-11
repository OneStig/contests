#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef int uci;
#define int long long
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

uci main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, d, L;
	cin >> n >> d >> L;

	vector<int> a(n);
	int maxim = 0;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		maxim = max(a[i], maxim);
	}

	sort(all(a));

	int l = maxim, r = maxim + L * n + 1000;
	while(r > l + 1) {
		int mid = (r + l) / 2;
		priority_queue <int> lst;
		bool ok = true;

		for(int i = 0; i < n && ok; ++i) {
			if((mid - a[i]) / d == 0) {
				ok = false;
			}

			else {
				lst.push((mid - a[i]) / d);
			}
		}

		if(ok) {
			while (lst.size() != 1) {
				int A = lst.top();
				lst.pop();
				int b = lst.top();
				lst.pop();
				if (A == 0 or b == 0) {
					ok = false;
					break;
				}
				else {
					lst.push(min(A,b) - 1);
				}
			}
		}

		if(ok) {
			r = mid;
		}

		else {
			l = mid;
		}
	}

	cout << r + L << "\n";
	return 0;
}
