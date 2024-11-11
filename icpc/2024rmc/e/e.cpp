#include <bits/stdc++.h>

using namespace std;

typedef int uci;
#define int long long
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

typedef array<int, 6> gs;

uci main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int r, c;
	cin >> r >> c;

	vector<string> g(r);
	for (auto& gx : g) cin >> gx;

	gs initial = {-1, -1, 0, 0, 0, 0};
	set<char> lowered = {'a', 'b', 'c', 'd'};
	set<char> raised = {'A', 'B', 'C', 'D'};
	set<char> switches = {'1', '2', '3', '4'};
	set<char> either = {'A', 'B', 'C', 'D', 'a', 'b', 'c', 'd'};
	vector<int> dr = {1, -1, 0, 0}, dc = {0, 0, 1, -1};

	vector<int> ends;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (g[i][j] == 'S') {
				if (initial[0] == -1) {
					initial[0] = i * c + j;
				}
				else {
					initial[1] = i * c + j;
				}
			}
			else if (g[i][j] == 'E') {
				ends.push_back(i * c + j);
			}
		}
	}

	sort(all(ends));

	if (initial[0] > initial[1]) {
		swap(initial[0], initial[1]);
	}

	// for (int i = 0; i < 6; i++) {
	// 	cerr << initial[i] << ' ';
	// }

	int ans = -1;
	queue<gs> bfs;
	map<gs, int> dist;
	bfs.push(initial);
	dist[initial] = 0;

	while (sz(bfs)) {
		gs cur = bfs.front();
		int curdist = dist[cur];
		bfs.pop();

		if (cur[0] == ends[0] && cur[1] == ends[1]) {
			ans = curdist;
			break;
		}

		int ar = cur[0] / c, ac = cur[0] % c;
		int br = cur[1] / c, bc = cur[1] % c;

		// cerr << "bfs:\n" << ar << ' ' << ac << ' ' << br << ' ' << bc << '\n';

		for (int dir = 0; dir < 4; dir++) {
			int nar = ar + dr[dir], nac = ac + dc[dir];
			int nbr = br + dr[dir], nbc = bc + dc[dir];

			// first check if step out of bounds
			if (nar < 0 || nar >= r || nac < 0 || nac >= c ||
				nbr < 0 || nbr >= r || nbc < 0 || nbc >= c) {
				continue;
			}

			// check if we step into bottomless pit
			if (g[nar][nac] == '*' || g[nbr][nbc] == '*') {
				continue;
			}

			bool amove = true, bmove = true;
			// if either hits fixed or raised obstacle, move them back
			if (g[nar][nac] == '#' ||
				(lowered.find(g[nar][nac]) != lowered.end() && cur[g[nar][nac] - 'a' + 2]) ||
				(raised.find(g[nar][nac]) != raised.end() && !cur[g[nar][nac] - 'A' + 2])) {
				nar = ar, nac = ac;
				amove = false;
			}

			if (g[nbr][nbc] == '#' ||
				(lowered.find(g[nbr][nbc]) != lowered.end() && cur[g[nbr][nbc] - 'a' + 2]) ||
				(raised.find(g[nbr][nbc]) != raised.end() && !cur[g[nbr][nbc] - 'A' + 2])) {
				nbr = br, nbc = bc;
				bmove = false;
			}

			gs nextst = cur;

			// if we move onto a switch, check that the other pers is not blocking
			if (amove && switches.find(g[nar][nac]) != switches.end()) {
				// if blocked, revert otherwise flip state
				int which = g[nar][nac] - '1';
				if (either.find(g[nbr][nbc]) != either.end() && (g[nbr][nbc] - 'a' == which || g[nbr][nbc] - 'A' == which)) {
					nar = ar, nac = ac;
					continue;
				}
				else {
					nextst[which + 2] = !nextst[which + 2];
				}
			}

			if (bmove && switches.find(g[nbr][nbc]) != switches.end()) {
				// if blocked, revert otherwise flip state
				int which = g[nbr][nbc] - '1';
				if (either.find(g[nar][nac]) != either.end() && (g[nar][nac] - 'a' == which || g[nar][nac] - 'A' == which)) {
					nbr = br, nbc = bc;
					continue;
				}
				else {
					nextst[which + 2] = !nextst[which + 2];
				}
			}

			// update new game state
			nextst[0] = nar * c + nac;
			nextst[1] = nbr * c + nbc;

			// can't be ontop of each other
			if (nextst[0] == nextst[1]) {
				continue;
			}

			if (nextst[0] > nextst[1]) {
				swap(nextst[0], nextst[1]);
			}

			if (dist.find(nextst) == dist.end()) {
				dist[nextst] = curdist + 1;
				bfs.push(nextst);
			}
		}
	}

	cout << ans << '\n';
}
