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

const int MAX_N = 1e5 + 5;

array<int, 2> pylons[MAX_N];

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;

    cin >> n;

    set<int> yvals;

    for (int i = 0; i < n; i++) {
        int x, y, a;
        cin >> x >> y >> a;

        pylons[y][a - 1]++;
        yvals.insert(y);
    }

    int last = -5;

    int ans{};

    for (int cur : yvals) {
        if (last == cur - 1) {
            int prev = pylons[last][0] + pylons[last][1];
            int add = min(prev, pylons[cur][0] + pylons[cur][1]);

            if (add > pylons[cur][1]) {
                pylons[cur][0] -= add - pylons[cur][1];
            }

            ans += add;
        }

        last = cur;
    }

    cout << ans << '\n';
}
