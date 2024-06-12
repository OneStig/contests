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

    int m;
    cin >> m;

    if (m == 1) {
        cout << "1\n";
        return 0;
    }

    unordered_set<int> isfact;
    vector<int> factors;

    for (int i = 1; i <= sqrt(m); i++) {
        if (m % i == 0) {
            factors.push_back(i);
            isfact.insert(i);

            if (m / i != i) {
                factors.push_back(m / i);
                isfact.insert(m / i);
            }
        }
    }

    vector<int> fib = {1, 1};
    unordered_map<int, int> gfact;
    gfact[1] = 0;

    while (fib.back() < m) {
        fib.push_back(fib[sz(fib) - 1] + fib[sz(fib) - 2]);
        if (isfact.contains(fib.back())) {
            gfact[fib.back()] = sz(fib) - 1;
        }
    }

    sort(all(factors));

    for (int& f: factors) {
        if (gfact.contains(f)) {
            for (int x : fib) {
                if (!gfact.contains(x) || x > m / f) continue;

                int cur = f * x;

                if (isfact.contains(cur)) {
                    if (!gfact.contains(cur)) {
                        gfact[cur] = gfact[f] + gfact[x] + 1;
                    }
                    else {
                        gfact[cur] = min(gfact[cur], gfact[f] + gfact[x] + 1);
                    }
                }
            }
        }
    }

    if (gfact.contains(m)) {
        cout << gfact[m] << '\n';
    }
    else {
        cout << "NIE\n";
    }
}
