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
        int n, k, q;
        cin >> n >> k >> q;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] -= i;
        }

        vector<int> ans(n);
        map<int, int> count;
        map<int, int> vals;
        for (int i = 0; i < k; i++) {
            count[a[i]]++;
        }

        for (auto [x, y] : count) {
            vals[y]++;
        }

        ans[k - 1] = prev(vals.end())->first;

        for (int i = k; i < n; i++) {
            if (--vals[count[a[i - k]]] == 0) {
                vals.erase(count[a[i - k]]);
            }
            count[a[i - k]]--;
            vals[count[a[i - k]]]++;

            if (--vals[count[a[i]]] == 0) {
                vals.erase(count[a[i]]);
            }
            count[a[i]]++;
            vals[count[a[i]]]++;

            ans[i] = prev(vals.end())->first;
        }

        while (q--) {
            int l, r;
            cin >> l >> r;
            r--;

            cout << k - ans[r] << '\n';
        }
    }
}
