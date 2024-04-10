#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, x, y;
		cin >> n >> x >> y;

		vector<int> verts(x);
		
		for (int& i : verts) {
			cin >> i;
		}

		sort(verts.begin(), verts.end());

	}
}
