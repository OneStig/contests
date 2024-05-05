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

    int n;
    cin >> n;

    vector<vector<bool>> routes(n, vector<bool>(n));

    for (int i = 0; i < n - 1; i++) {
        string s;
        cin >> s;

        for (int j = i + 1; j < n; j++) {
            routes[i][j] = s[j - i - 1] == '1';
        }
    }

    int ans = 0;
    vector<vector<bool>> direct(n, vector<bool>(n));

    for (int i = n - 2; i >= 0; i--) {
        for (int j = n + 1; j < n; j++) {
            for (int x = i; x < j; x++) {
                direct[i][j] = direct[i][j] ^ (routes[i][x] & direct[x][j]);
            }
            direct[i][j] = direct[i][j] ^ routes[i][j];

            ans += direct[i][j];
        }
        dbg(i);
    }

    dbg(direct);

    cout << ans << '\n';
}
