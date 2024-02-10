#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	ll n, m;
	cin >> n >> m;

	if (m <= n) {
		cout << n - m << endl;
		return 0;
	}

	vector<int> step(20001, -1);
	step[n] = 0;
	queue<ll> bfs;
	bfs.push(n);

	while (!bfs.empty()) {
		ll cur = bfs.front();
		//debug(cur);
		bfs.pop();

		if (cur == m) {
			break;
		}

		if (2 * cur < step.size() && step[2 * cur] == -1) {
			step[2 * cur] = step[cur] + 1;
			bfs.push(2 * cur);
		}
		
		if (cur - 1 > 0 && step[cur - 1] == -1) {
			step[cur - 1] = step[cur] + 1;
			bfs.push(cur - 1);
		}
	}

	cout << step[m] << endl;
}
