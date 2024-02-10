#include <bits/stdc++.h>

using namespace std;

int main() {
	int v;
	cin >> v;

	vector<int> a(10);

	int digits = 0;
	int biggest = 0;

	for (int i = 1; i <= 9; i++) {
		cin >> a[i];
		
		if (v / a[i] >= digits) {
			if (v / a[i] == digits) {
				biggest = max(biggest, i);
			}
			else {
				biggest = i;
			}

			digits = v / a[i];
		}
	}

	if (digits == 0) {
		cout << -1 << endl;
		return 0;
	}


	cout << endl;
}

