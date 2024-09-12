#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef int uci;
#define int long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

#define f first
#define s second

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int r, c;
    cin >> r >> c;
    map<int, pair<int, int>> where, target;
    vector<vector<int>> cur(r, vector<int>(c)), need(r, vector<int>(c));

    for (int row = 0; row < r; row++) {
        for (int col = 0; col < c; col++) {
            cin >> cur[row][col];
            where[cur[row][col]] = {row, col};
        }
    }

    for (int row = 0; row < r; row++) {
        for (int col = 0; col < c; col++) {
            cin >> need[row][col];
            target[need[row][col]] = {row, col};
        }
    }

    vector<array<int, 4>> swaps;
    auto doswap = [&swaps, &where, &cur](int x, int y) {
        swaps.push_back({where[x].f + 1, where[x].s + 1, where[y].f + 1, where[y].s + 1});
        swap(where[x], where[y]);
        swap(cur[where[x].f][where[x].s], cur[where[y].f][where[y].s]);
    };

    for (int i = 1; i <= r * c; i++) {
        if (where[i] == target[i]) continue;
        int a = where[i].f, b = target[i].f;
        // move i from row a to b

        // 1. find correct position where i needs to be (since everything else already processed)
        int apos = where[i].s;
        int bpos = lower_bound(all(cur[b]), i) - cur[b].begin();

        // 2. the number at bpos needs to swap with smallest element it will fit under
        while (cur[b][bpos] != i) {
            int swapwith = *prev(lower_bound(all(cur[a]), cur[b][bpos]));
            doswap(cur[b][bpos], swapwith);
        }
    }

    cout << sz(swaps) << '\n';
    for (auto& ans : swaps) {
        cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ' ' << ans[3] << '\n';
    }
}
