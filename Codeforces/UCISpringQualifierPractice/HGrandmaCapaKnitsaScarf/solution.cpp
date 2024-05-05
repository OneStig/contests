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
#define ld long double
#define szof(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int ans = INT_MAX;

        for (char c = 'a'; c <= 'z'; c++) {
            int l = 0, r = s.size() - 1;

            int bad = 0;
            bool fail = 0;
            while (l < r) {
                if (s[l] == s[r]) {
                    l++;
                    r--;
                }
                else {
                    if (s[l] == c) {
                        l++;
                        bad++;
                    }
                    else if (s[r] == c) {
                        r--;
                        bad++;
                    }
                    else {
                        fail = 1;
                        break;
                    }
                }
            }

            if (!fail) {
                ans = min(ans, bad);
            }
        }

        cout << (ans == INT_MAX ? -1 : ans) << '\n';
    }
}
