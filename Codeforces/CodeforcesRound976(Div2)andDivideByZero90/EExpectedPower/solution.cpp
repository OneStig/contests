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

const int MAX_B = 10;
const int MAX_P = 1e4;
const int MOD = 1e9 + 7;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), p(n);
        for (int& x : a) cin >> x;
        for (int& x : p) cin >> x;

        int ev{};
        for (int b = 0; b < MAX_B; b++) {
            int m = 1ll << b;
            int sum{};
            for (int i = 0; i < n; i++) {
                if (a[i] & m) {
                    sum += p[i];
                }
            }

            dbg(sum, m);

            ev += (sum % MAX_P) * m;
        }

        dbg(ev);
    }
}
