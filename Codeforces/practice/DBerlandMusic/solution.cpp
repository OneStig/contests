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
        string s;
        cin >> n;
        
        vector<int> p(n);
        for (int& x : p) cin >> x;
        cin >> s;

        vector<array<int, 3>> songs;

        int lcount{};

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                lcount++;
                songs.push_back({1, p[i], i});
            }
            else {
                songs.push_back({0, p[i], i});
            }
        }

        sort(all(songs));

        vector<int> ans(n);

        for (int i = 1; i <= n; i++) {
            ans[songs[i - 1][2]] = i;
        }

        for (int& k : ans) {
            cout << k << ' ';
        }
        cout << '\n';
    }
}