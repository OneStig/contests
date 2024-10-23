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

vector<int> nums;

void solve() {
    int a, b, m;
    cin >> a >> b >> m;

    int ans{};
    for (int& x : nums) {
        if (x % m == 0 && x >= a && x <= b) {
            // dbg(x, m);
            ans++;
        }
    }

    cout << ans << '\n';
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector<int> last;

    for (int i = 1; i <= 9; i++) {
        nums.push_back(i);
        last.push_back(i);
    }

    for (int len = 2; len <= 9; len++) {
        vector<int> cur;
        for (int p : last) {
            int r = p % 10;
            int l;

            int digs{10};
            int tmp = p;
            while (tmp != 0) {
                digs *= 10;
                l = tmp % 10;
                tmp /= 10;
            }

            p *= 10;

            for (int nl = (len == 2 ? l - 1 : l); nl > 0; nl--) {
                for (int nr = (len == 2 ? r - 1 : r); nr > 0; nr--) {
                    int nxt = nl * digs + p + nr;
                    // dbg(nl, p, nr, nxt);
                    cur.push_back(nxt);
                }
            }
        }

        sort(all(cur));
        nums.insert(nums.end(), all(cur));
        // dbg(nums.back());
        // dbg(len, sz(cur));

        last = cur;
    }

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}

// 1111111112111111111

// 1000000000000000000
