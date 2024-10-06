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

const int MAX_N = 1e7;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector<bool> isp(MAX_N + 1, 1);
    vector<int> primes;
    isp[0] = isp[1] = 0;
    for (int i = 2; i <= MAX_N; i++) {
        if (isp[i]) {
            primes.push_back(i);
            if (i * i <= MAX_N) {
                for (int j = i * i; j <= MAX_N; j+= i) {
                    isp[j] = 0;
                }
            }
        }
    }


    vector<int> ans(sz(primes));
    for (int i = 0; i < sz(primes); i++) {
        if (i != 0) {
            ans[i] += ans[i - 1];
        }
        if (isp[primes[i] + 2] && i + 1 < sz(primes)) {
            ans[i + 1]++;
        }
    }

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        cout << "Case #" << tc << ": ";

        int n;
        cin >> n;

        if (n < 5) {
            cout << 0 << '\n';
        }
        else {
            int pos = prev(upper_bound(all(primes), n)) - primes.begin();
            cout << (ans[pos] ? ans[pos] + 1 : 0) << '\n';
        }
    }
}
