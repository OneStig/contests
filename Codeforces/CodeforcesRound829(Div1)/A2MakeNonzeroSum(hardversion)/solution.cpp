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

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int sum{};
        for (int& x : a) {
            cin >> x;
            sum += x;
        }

        if (sum % 2) {
            cout << -1 << '\n';
            continue;
        }

        vector<int> parts;
        int seen = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] != 0) {
                if (seen != -1) {
                    // from seen to i
                    if (a[seen] + a[i] != 0) {
                        parts.push_back(i);
                    }
                    seen = -1;
                }
                else {
                    seen = i;
                }
            }
        }

        int nxt = 0;
        vector<pair<int, int>> ans;
        for (int i = 1; i <= n; i++) {
            if (nxt < sz(parts) && parts[nxt] == i) {
                ans.push_back({parts[nxt], parts[nxt] + 1});
                nxt++;
                i++;
            }
            else {
                ans.push_back({i, i});
            }
        }

        cout << sz(ans) << '\n';
        for (auto& x : ans) {
            cout << x.first << ' ' << x.second << '\n';
        }
    }
}
