#include <bits/stdc++.h>

using namespace std;

#define ld long double

int main() {
	ld a, b, c, d;
	cin >> a >> b >> c >> d;

	ld win = a / b;
	ld nextwin = (1 - a / b) * (1 - c / d);
	cout << setprecision(12) << win / (1 - nextwin);
}
