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
        int n;
        cin >> n;

        vector<pair<int, int>> x(n);
        vector<int> sfx(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i].first;
            x[i].second = i;
        }

        sort(all(x));

        for (int i = n - 2; i >= 0; i--) {
            sfx[i] = sfx[i + 1] + x[i + 1].first;
        }

        int left{};
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int cur = i * x[i].first - left;
            cur += sfx[i] - (n - i - 1) * (x[i].first - 1);
            left += x[i].first - 1; // ranges are inclusive
            cur++; // because [x_i, x_i]

            ans[x[i].second] = cur;
        }

        for (int& a : ans) {
            cout << a << ' ';
        }
        cout << '\n';
    }
}
