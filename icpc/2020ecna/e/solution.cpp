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

char i2c(int x) {
    if (x == 36) return ' ';
    if (x < 26) return 'A' + x;
    return x - 26 + '0';
}

int c2i(char c) {
    if (c == ' ') return 36;
    if (c >= 'A') return c - 'A';
    return c - '0' + 26;
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> m(n, vector<int>(n));

    for (auto& x : m) for (auto& y : x) cin >> y;

    string s;
    getline(cin, s);
    getline(cin, s);

    vector<int> inp;
    for (char c : s) {
        inp.push_back(c2i(c));
    }

    while (sz(inp) % n != 0) {
        inp.push_back(36);
    }

    vector<int> out(sz(inp));

    for (int i = 0; i < sz(inp); i+= n) {
        for (int j = 0; j < n; j++) {
            int pos = i + j;

            for (int k = 0; k < n; k++) {
                out[pos] += inp[i + k] * m[j][k];
                out[pos] %= 37;
            }
        }
    }

    for (int& x : out) {
        cout << i2c(x);
    }
    cout << '\n';
}
