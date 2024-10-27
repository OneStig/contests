#include <bits/stdc++.h>
#include <cstdint>

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
#define int unsigned long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

#define gcd gcd<uint64_t>

int m, n, p;

map<array<int, 3>, pair<int, int>> cache;

pair<int, int> solve(int i, int j, int p) {
    if (i == 0) {
        return {1, 1};
    }

    if (p == 0 || j == 0) {
        return {0, 1};
    }

    if (i > j) {
        return {0, 1};
    }

    if (cache.contains({i, j, p})) {
        return cache[{i, j, p}];
    }

    auto [a, b] = solve(i - 1, j - 1, p - 1);
    auto [c, d] = solve(i, j - 1, p - 1);
    a *= 2 * i;
    b *= j;
    c *= (j - 2 * i);
    d *= j;
    int e = a * d + c * b, f = b * d;
    int x = e / gcd(e, f), y = f / gcd(e, f);
    cache[{i, j, p}] = {x, y};
    return {x, y};
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> m >> n >> p;

    if (p == 0) {
        cout << "0/1" << '\n';
        return 0;
    }

    auto [a, b] = solve(n, m, p);
    auto [c, d] = solve(n, m, p - 1);
    int e = a * d - b * c, f = b * d;

    cout << e / gcd(e, f) << '/' << f / gcd(e, f) << '\n';
}
