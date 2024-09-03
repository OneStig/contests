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
        int x;
        cin >> x;

        int mn = 0, mx = 1000;

        vector<int> ans;
        while (x > 1) {
            if (x % 2) {
                ans.push_back(mn++);
                x--;
            }
            else {
                ans.push_back(mx--);
                x /= 2;
            }
        }

        reverse(all(ans));
        cout << sz(ans) << '\n';
        for (int& x : ans) cout << x << ' ';
        cout << '\n';
    }
}

// 1 -> 2
// 1, 2 -> 4
// 1, 2, 3 -> 8

// if x is odd -> tack min on to end
// if x is even -> tack max on to end
// repeat until x is 0?
