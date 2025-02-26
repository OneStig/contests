#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "cpp-dump/cpp-dump.hpp"
#define dbg(...) cpp_dump(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef int uci;
#define int long long
#define ld long double
#define ve vector
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
typedef pair<int, int> pii;

uci main() {
	int n = 1;
	while (n != 0) {
		cin >> n;
		if (n == 0) {
			break;
		}
		vector<int> a;
		for (int i = 0; i < n; i++) {
			int k;
			cin >> k;
			a.push_back(k);
		}
		reverse(a.begin(), a.end());
		bool good = true;
		vector<vector<int>> grid(n, vector<int>(n, 0));
		int left = 0;
		int right = n - 1;
		while (left <= right) {
			//cout << left << " " << right << " " << a << "\n";
			if (left == right) {
				grid[left][left] = a[left];
				break;
			}
			if (a[left] == -1) {
				if (a[right] == -1) {
					a[right] = 1;
				}
				a[left] = a[right];
			}
			if (a[right] == -1) {
				a[right] = a[left];
			}
			if (a[left] == a[right]) {
				for (int i = left; i <= right; i++) {
					grid[left][i] = a[i];
					grid[right][i] = a[left + right - i];
					grid[i][left] = a[left + right - i];
					grid[i][right] = a[i];
				}
				break;
			}
			if (left + 1 == right) {
				good = false;
				break;
			}
			int ra = -1;
			int lb = -1;
			for (int i = left; i <= right; i++) {
				if (a[i] == a[left] or a[i] == -1) {
					ra = i;
				}
				if (a[i] == a[right] or a[i] == -1) {
					if (lb == -1) {
						lb = i;
					}
				}
			}
			//cout << ra << " " << lb << "\n";
			if (ra <= lb) {
				good = false;
				break;
			}
			
			//grid[left][ra] = a[left];
			//grid[ra][right] = a[left];
			//grid[right][left + right - ra] = a[left];
			//grid[left + right - ra][left] = a[left];
			//grid[left][lb] = a[right];
			//grid[lb][right] = a[right];
			//grid[right][left + right - lb] = a[right];
			//grid[left + right - lb][left] = a[right];
 
			for (int i = lb ; i <= ra; i++) {
				grid[left][i] = a[i];
				grid[i][right] = a[i];
				grid[right][left + right - i] = a[i];
				grid[left + right - i][left] = a[i];
			}
			for (int i = lb; i <= ra; i++) {
				a[i] = -1;
			}
			left += 1;
			right -= 1;
		}
		//cout << grid << "\n";
		if (!good) {
			cout << "No\n";
			continue;
		}
		cout << "Yes\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << max(0ll,grid[i][j]) << " ";
			}
			cout << "\n";
		}
	}
 
}
