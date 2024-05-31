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

#define ll long long
typedef int uci;
#define int long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

void solve() {
    int a, b, n, m;
    cin >> a >> b >> n >> m;

    deque<array<int, 2>> horiz, vert;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        vert.push_back({x, i});
        horiz.push_back({y, i});
    }

    sort(all(horiz));
    sort(all(vert));

    set<int> erased;
    int u{1}, d{a}, l{1}, r{b};

    int alice{}, bob{};
    bool turn{};

    for (int i = 0; i < m; i++) {
        char dir;
        int k, cur{};
        cin >> dir >> k;

        if (dir == 'U') {
            u += k;

            while (sz(vert) && vert.front()[0] < u) {
                auto [x, i] = vert.front();
                vert.pop_front();
                if (!erased.contains(i)) {
                    erased.insert(i);
                    cur++;
                }
            }
        }
        else if (dir == 'D') {
            d -= k;

            while (sz(vert) && vert.back()[0] > d) {
                auto [x, i] = vert.back();
                vert.pop_back();
                if (!erased.contains(i)) {
                    erased.insert(i);
                    cur++;
                }
            }
        }
        else if (dir == 'L') {
            l += k;

            while (sz(horiz) && horiz.front()[0] < l) {
                auto [y, i] = horiz.front();
                horiz.pop_front();
                if (!erased.contains(i)) {
                    erased.insert(i);
                    cur++;
                }
            }
        }
        else if (dir == 'R') {
            r -= k;

            while (sz(horiz) && horiz.back()[0] > r) {
                auto [y, i] = horiz.back();
                horiz.pop_back();
                if (!erased.contains(i)) {
                    erased.insert(i);
                    cur++;
                }
            }
        }

        if (turn) {
            bob += cur;
        }
        else {
            alice += cur;
        }

        turn = !turn;
    }

    cout << alice << ' ' << bob << '\n';
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
