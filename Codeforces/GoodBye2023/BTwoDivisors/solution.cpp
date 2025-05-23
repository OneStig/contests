#include <bits/stdc++.h>

using namespace std;

int spf(int n) {
    if (n % 2 == 0) return 2;

    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return i;
    }

    return n;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int a, b;
		cin >> a >> b;

		if (a == 1) {
			cout << b * b << endl;
			continue;
		}

		if (b % a == 0) {
			cout << b * (b / a) << endl;
			continue;
		}

		cout << b * spf(a) << endl;
	}
}
