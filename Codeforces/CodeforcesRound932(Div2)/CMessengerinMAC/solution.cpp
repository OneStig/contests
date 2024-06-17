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

void solve() {
    int n, mx, ans{};
    cin >> n >> mx;

    // order of a and b are swapped
    vector<array<int, 2>> msgs(n);
    for (auto& x : msgs) {
        cin >> x[1] >> x[0];

        if (x[1] <= mx) {
            ans = 1;
        }
    }

    if (ans == 0) {
        cout << 0 << '\n';
        return;
    }

    sort(all(msgs));

    for (int l = 0; l < n; l++) {
        int acost = msgs[l][1];
        priority_queue<int> take;
        take.push(msgs[l][1]);

        for (int r = l + 1; r < n; r++) {
            int bcost = msgs[r][0] - msgs[l][0];
            acost += msgs[r][1];
            take.push(msgs[r][1]);

            while (!take.empty() && acost + bcost > mx) {
                int big = take.top();
                take.pop();
                acost -= big;
            }

            if (acost + bcost <= mx) {
                ans = max(ans, sz(take));
            }
        }
    }

    cout << ans << '\n';
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
