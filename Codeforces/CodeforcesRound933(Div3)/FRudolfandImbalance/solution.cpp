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

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n), d(m), f(k);
        for (int& x : a) cin >> x;
        for (int& x : d) cin >> x;
        for (int& x : f) cin >> x;

        set<int> fb{all(f)};

        priority_queue<int> gaps;

        int pos = 0;
        for (int i = 1; i < n; i++) {
            int cur = a[i] - a[i - 1];
            if (sz(gaps) == 0 || cur > gaps.top()) {
                pos = i;
            }
            gaps.push(cur);
        }

        int gap = gaps.top();
        gaps.pop();

        if (sz(gaps) && gap == gaps.top()) {
            cout << gap << '\n';
            continue;
        }

        // otherwise lets find pair a + b to close the gap

        int second = 0;

        if (sz(gaps)) {
            second = gaps.top();
        }

        int start = a[pos - 1], end = a[pos];
        int target = start + gap / 2;
        int ans = gap;

        for (int& a : d) {
            auto it = fb.lower_bound(target - a);

            if (it != fb.end()) {
                int test = *it + a;
                ans = min(ans, max(second, max(end - test, test - start)));
            }

            if (it != fb.begin()) {
                it--;
                int test = *it + a;
                ans = min(ans, max(second, max(end - test, test - start)));
            }
        }

        cout << ans << '\n';
    }
}
