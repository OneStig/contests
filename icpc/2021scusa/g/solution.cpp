#include <algorithm>
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

    string alph;
    cin >> alph;
    int asize = sz(alph);

    string s;
    cin >> s;
    int n = sz(s);
    int q;
    cin >> q;

    int mn = 1;
    set<char> seen;
    map<char, vector<int>> pos;
    for (int i = 0; i < n; i++) {
        pos[s[i]].push_back(i);
        seen.insert(s[i]);

        if (sz(seen) == asize) {
            seen = set<char>();
            mn++;
        }
    }

    while (q--) {
        string query;
        cin >> query;

        if (sz(query) != mn) {
            cout << "0\n";
            continue;
        }

        // check if subsequence
        bool good = 0;
        int nxt = -1;
        for (char c : query) {
            auto it = upper_bound(all(pos[c]), nxt);
            if (it == pos[c].end()) {
                good = 1;
                break;
            }

            nxt = *it;
        }

        cout << good << '\n';
    }

    // dbg(mn);
}
