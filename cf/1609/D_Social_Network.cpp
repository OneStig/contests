#include <bits/stdc++.h>

using namespace std;

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x; return true;
	}
};

int main() {
    long long n, d;

    cin >> n >> d;

    vector<long long> point(n + 1);

    int m = 0;

    DSU dsu(n);

    for (int i = 1; i < d; i++) {
        int a, b;
        cin >> a >> b;

        
        m += 1 - dsu.unite(a - 1, b - 1);

        vector<int> srt;
        unordered_map<int, bool> used;

        for (int i = 0; i < n; i++) {
            if (!used[dsu.get(i)]) {
                srt.push_back(dsu.size(i));
                used[dsu.get(i)] = 1;
            }
        }

        sort(srt.begin(), srt.end());

        long long ans = 0;

        for (int j = srt.size() - 1; j >= srt.size() - 1 - m; j--) {
            ans += srt[j];
        }

        cout << ans - 1 << endl;
    }

    cout << d << endl;
}