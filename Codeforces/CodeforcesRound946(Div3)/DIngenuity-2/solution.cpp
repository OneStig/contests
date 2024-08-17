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
        string s;
        cin >> n >> s;

        int north{}, south{}, east{}, west{};

        for (char c : s) {
            if (c == 'N') north++;
            else if (c == 'S') south++;
            else if (c == 'E') east++;
            else west++;
        }

        dbg(north, south, east, west);

        if ((north + south) % 2 == 1 || (east + west) % 2 == 1 ||
            s == "NS" || s == "SN" || s == "EW" || s == "WE") {
            cout << "NO" << '\n';
            continue;
        }

        string ans = "";

        int nc{}, sc{}, ec{}, wc{};

        for (char c : s) {
            if ((c == 'N' && nc % 2 == 0) || (c == 'S' && sc % 2 == 0) ||
                (c == 'E' && ec % 2 == 1) || (c == 'W' && wc % 2 == 1)) {
                ans += "R";
            }
            else {
                ans += "H";
            }

            if (c == 'N') nc++;
            else if (c == 'S') sc++;
            else if (c == 'E') ec++;
            else wc++;
        }

        cout << ans << '\n';
    }
}
