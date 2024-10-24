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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);

        int ans = 0;
        for (int& x : a) { cin >> x; ans = max(ans, x); }

        int cap = a.back() + 1;

        for (int i = n - 2; i >= 0; i--) {
            if (a[i] < cap) {
                int l = a[i], r = cap;

                while (l < r) {
                    int mid = (l + r + 1) / 2;
                    int cost = mid - a[i];
                    int needed = mid - 1;
                    for (int j = i + 1; a[j] < needed; j++, needed--) {
                        // cap should prevent loop from exceeding
                        cost += needed - a[j];
                    }

                    // dbg(l, r, cost, k);
                    if (cost > k) {
                        r = mid - 1;
                    }
                    else {
                        l = mid;
                    }
                }

                ans = max(ans, l);
            }

            cap = max(cap + 1, a[i] + 1);
        }

        cout << ans << '\n';
    }
}
