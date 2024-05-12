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

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> pos, neg;
        int zeros{};
        int mx = INT_MIN, mn = INT_MAX;

        for (int& x : a) {
            cin >> x;
            if (x == 0) {
                zeros++;
            }
            else if (x > 0) {
                pos.push_back(x);
            }
            else {
                neg.push_back(x);
            }

            mx = max(mx, x);
            mn = min(mn, x);
        }

        int diff = mx - mn;

        if (diff == 0) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        while (zeros--) {
            cout << 0 << " ";
        }

        int sum = 0;
        while (sz(pos) || sz(neg)) {
            if (sum <= 0) {
                sum += pos.back();
                cout << pos.back() << ' ';
                pos.pop_back();
            }
            else {
                sum += neg.back();
                cout << neg.back() << ' ';
                neg.pop_back();
            }
        }

        cout << '\n';
    }
}
