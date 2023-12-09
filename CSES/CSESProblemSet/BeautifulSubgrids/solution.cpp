#include <bits/stdc++.h>
#pragma GCC target("popcnt")

using namespace std;

bitset<3000> grid[3000];

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> grid[i];
	}

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int count = (grid[i] & grid[j]).count();
			ans += count * (count - 1);
		}
	}

	cout << ans / 2 << endl;
}
