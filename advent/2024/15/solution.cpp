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

    string x;
    cin >> x;


    vector<string> g;
    int i = 0;
    int ar, ac;
    while (x[0] == '#') {
        g.push_back(x);
        for (int j = 0; j < sz(x); j++) {
            if(x[j] == '@') {
                ar = i;
                ac = j;
                break;
            }
        }
        
        cin >> x;

        i++;
    }

    string k;
    while (cin >> k) {
        x += k;
    }

    int R = sz(g);
    int C = sz(g[0]);

    int ans = 0;

    map<char, pair<int, int>> dir = {
        {'<', {0, -1}},
        {'^', {-1, 0}},
        {'>', {0, 1}},
        {'v', {1, 0}}
    };

    for (char mv : x) {
        auto [dr, dc] = dir[mv];
        bool found = 0;
        int stop = 0;
        int br = ar;
        int bc = ac;

        for (; 1; stop++) {
            br += dr;
            bc += dc;

            if (g[br][bc] == '#') {
                break;
            }

            if (g[br][bc] == '.') {
                found = 1;
                break;
            }
        }

        dbg(ar, br);
        dbg(found, stop, br, bc, dr, dc);

        if (found) {
            for (int count = 0; count <= stop; count++) {
                g[br][bc] = g[br - dr][bc - dc];
                br -= dr;
                bc -= dc;
            }

            g[ar][ac] = '.';
            ar += dr;
            ac += dc;
        }

        for (auto& k : g) {
            dbg(k);
        }
    }

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (g[r][c] == 'O') {
                ans += r * 100 + c;
            }
        }
    }

    dbg(ans);
}
