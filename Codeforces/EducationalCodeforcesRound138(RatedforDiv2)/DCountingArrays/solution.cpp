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

const int MOD = 998244353;
const int MAX_N = 3e5 + 1;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    bitset<MAX_N> isPrime;

    const int S = 548, R = MAX_N / 2;
    vector<int> pr = {2}, sieve(S + 1); pr.reserve(uci(MAX_N/log(MAX_N) * 1.1));
    vector<pair<int, int>> cp;

    for (int i = 3; i <= S; i += 2) {
        if (!sieve[i]) {
            cp.push_back({i, i * i / 2});
            for (int j = i * i; j <= S; j+= 2 * i) {
                sieve[j] = 1;
            }
        }
    }

    for (int L = 1; L <= R; L += S) {
        array<bool, S> block{};
        for (auto &[p, idx] : cp)
            for (int i = idx; i < S + L; idx = (i += p)) block[i - L] = 1;

        for (int i = 0; i < min(S, R - L); i++) {
            if (!block[i]) pr.push_back((L + i) * 2 + 1);
        }
    }

    for (int i : pr) isPrime[i] = 1;

    int ans{}, primeFacts{1}, nextm{1}, bad{1};

    for (int i = 1; i <= n; i++) {
        if (primeFacts <= m && isPrime[i]) {
            primeFacts *= i;
        }

        nextm = m % MOD * nextm % MOD;
        bad = (m / primeFacts) % MOD * bad % MOD;
        ans = (ans + nextm - bad + MOD) % MOD;
    }

    cout << ans << '\n';
}
