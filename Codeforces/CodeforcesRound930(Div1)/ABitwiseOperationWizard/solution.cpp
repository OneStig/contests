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

char query(int a, int b, int c, int d) {
    cout << "? " << a << ' ' << b << ' ' << c << ' ' << d << endl;
    char x;
    cin >> x;
    return x;
}

void answer(int i, int j) {
    cout << "! " << i << ' ' << j << endl;
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int mx{};
        for (int i = 1; i < n; i++) {
            if (query(mx, mx, i, i) == '<') {
                mx = i;
            }
        }

        int mxt{};
        vector<int> options;
        options.push_back(0);
        for (int i = 1; i < n; i++) {
            if (i == mx) continue;
            char test = query(mx, mxt, mx, i);
            if (test == '=') {
                options.push_back(i);
            }
            else if (test == '<') {
                options = vector<int>();
                options.push_back(i);
                mxt = i;
            }
        }

        int mn{options.back()};
        options.pop_back();

        while (!options.empty()) {
            int cur = options.back();
            options.pop_back();

            if (query(mn, mn, cur, cur) == '>') {
                mn = cur;
            }
        }

        answer(mx, mn);
    }
}
