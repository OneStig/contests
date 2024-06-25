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

    int n;
    cin >> n;

    vector<int> ans(10);

    int place = 1;
    for (int d = 0; d < 10; d++, place *= 10) {
        int above = n / place / 10;
        int cur = (n / place) % 10;

        for (int i = 1; i <= 9; i++) {
            ans[i] += above * place;
            if (i == cur) {
                ans[i] += n - (n / place * place) + 1;
            }
            else if (i < cur) {
                ans[i] += place;
            }
        }

        // count 0 separately

        if (above > 0) {
            if (cur == 0) {
                ans[0] += (above - 1) * place + (n - n / place * place) + 1;
            }
            else {
                ans[0] += above * place;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        if (i != 0) {
            cout << ' ';
        }

        cout << ans[i];
    }

    cout << '\n';
}
