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

    int n, r;
    cin >> n >> r;

    map<int, int> cnt, pfx;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }

    int prev = 0;
    for (auto [x, y] : cnt) {
        pfx[x] = y + prev;
        prev = pfx[x];
    }

    vector<int> bombs;
    while (n) {
        int best{}, bpos;
        for (auto [x, y] : pfx) {
            int cur = y;
            int curpos = x - 2 * r;
            auto it = pfx.lower_bound(curpos);

            if (it != pfx.begin()) {
                --it;
                cur -= it->second;
            }

            if (cur > best) {
                best = cur;
                bpos = curpos;
            }
        }

        //dbg(cnt, best, bpos);

        int left = bpos, right = bpos + 2 * r;
        map<int, int> newcnt;

        for (auto [x, y] : cnt) {
            if (x < left || x > right) {
                newcnt[x] = y;
            }
            else {
                n -= y;
            }
        }

        bombs.push_back(bpos + r);

        cnt = newcnt;

        pfx = map<int, int>();
        int prev = 0;
        for (auto [x, y] : cnt) {
            pfx[x] = y + prev;
            prev = pfx[x];
        }
    }

    cout << sz(bombs) << '\n';

    for (auto& x : bombs) {
        cout << x << ' ';
    }

    cout << '\n';
}