#include <bits/stdc++.h>

using namespace std;

long long mod = (long long)(1e9 + 7);

int main() {
	int n;
	cin >> n;

	long long ans = 1;
	for (int i = 0; i < n; i++) {
		ans *= 2;
		ans %= mod;
	}

	cout << ans << endl;
}
