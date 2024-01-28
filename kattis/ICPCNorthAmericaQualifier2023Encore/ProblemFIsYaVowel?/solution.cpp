#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;

	int v{}, y{};

	for (char c : s) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
			v++;
		}
		else if (c == 'y') {
			y++;
		}
	}

	cout << v << " " << v + y << endl;
}
