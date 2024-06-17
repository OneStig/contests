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

const int MAX_R = 3e9;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    
    vector<int> k(n), w(n), c(n);

    for (int& x : k) cin >> x;
    for (int& x : w) cin >> x;
    for (int& x : c) cin >> x;

    int q;
    cin >> q;

    while (q--) {
        int x, y, z, b;
        cin >> x >> y >> z >> b;

        int l = b, r = MAX_R;
        string ans;
        while (1) {
            int mid = (l + r) / 2;

            auto kit = lower_bound(all(k), mid);
            auto wit = lower_bound(all(w), mid);
            auto cit = lower_bound(all(c), mid);

            int ko = min((int)(kit - k.begin()), x);
            int we = min((int)(wit - w.begin()), y);
            int ch = min((int)(cit - c.begin()), z);

            int total = ko + we + ch;

            if (total == b) {
                vector<pair<int, string>> possible = {
                    {k[ko - 1], "1 " + to_string(ko)},
                    {w[we - 1], "2 " + to_string(we)},
                    {c[ch - 1], "3 " + to_string(ch)}
                };
                sort(all(possible));
                ans = possible[2].second;
                break;
            }
            else if (total < b) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }

        cout << ans << '\n';
    }
}
