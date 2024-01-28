#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a, b;
	cin >> n >> a >> b;

	unordered_set<int> k;
	k.insert(a);
	k.insert(b);

	for (int i = 1; i < n; i++) {
		int w;
		cin >> w;

		k.erase(w);
	}

	if (k.size() > 1) {
		cout << -1 << endl;
	}
	else if (k.size() == 1) {
		cout << *(k.begin()) << endl;
	}
	else {
		for (int i = a; i <= b; i++) {
			cout << i << endl;
		}
	}
}
