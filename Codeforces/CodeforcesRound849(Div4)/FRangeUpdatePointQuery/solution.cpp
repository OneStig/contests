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

struct FT {
    vector<int> bit;
    int n;

    FT(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    int sum(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    void add(int idx, int val) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += val;
    }

    void range_add(int l, int r, int val) {
        add(l, val);
        add(r + 1, -val);
    }
};

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<int> a(n);
        for (int& x : a) cin >> x;

        FT ft(n);

        while (q--) {
            int type;
            cin >> type;

            if (type == 1) {
                int l, r;
                cin >> l >> r;

                ft.range_add(l - 1, r - 1, 1);
            }
            else if (type == 2) {
                int x;
                cin >> x;

                int reduce = ft.sum(x - 1);
                int cur = a[x - 1];

                while (reduce-- && cur > 9) {
                    int nxt{};
                    while (cur) {
                        nxt += cur % 10;
                        cur /= 10;
                    }
                    cur = nxt;
                }

                cout << cur << '\n';
            }
        }
    }
}
