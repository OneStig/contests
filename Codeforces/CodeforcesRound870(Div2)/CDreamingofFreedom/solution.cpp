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

const int MAX_N = 1e6;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector<bool> isprime(MAX_N + 1, 1);
    isprime[0] = 0;
    isprime[1] = 0;

    vector<int> primes;

    for (int i = 2; i <= MAX_N; i++) {
        if (isprime[i]) {
            primes.push_back(i);
        }

        if (isprime[i] && i * i <= MAX_N) {
            for (int j = i * i; j <= MAX_N; j += i) {
                isprime[j] = 0;
            }
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        if (n == 1) {
            cout << "YES\n";
            continue;
        }

        if (m >= n) {
            cout << "NO\n";
            continue;
        }

        bool yes = 1;
        for (int i = 0; i < sz(primes) && primes[i] <= sqrt(n); i++) {
            if (primes[i] > m) break;
            if (n % primes[i] == 0) {
                yes = 0;
                break;
            }
        }

        cout << (yes ? "YES" : "NO") << '\n';
    }
}
