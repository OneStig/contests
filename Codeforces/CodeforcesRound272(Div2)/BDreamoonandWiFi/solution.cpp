#include <bits/stdc++.h>

using namespace std;

long double fact(int n) {
	long double x = 1;
	while (n--) {
		x *= n;
	}

	return x;
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;

	int diff{}, count{};
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] == '+') {
			diff++;
		}
		else {
			diff--;
		}

		if (s2[i] == '+') {
			diff--;
		}
		else if (s2[i] == '-') {
			diff++;
		}
		else {
			count++;
		}
	}
	// count is 1, -1, 1.0
	// 2, -2, 0, 2
	// 3, -3, -1, 1, 3
	cout << diff << " " << count << endl;

	if (count % 2 != diff % 2) {
		cout << 0 << endl;
	}
	else {
		long long eventProb = 1 << count;
		long double ways = fact(count) / fact(diff) / fact(count - diff) / eventProb;

		cout << ways << endl;
	}
}
