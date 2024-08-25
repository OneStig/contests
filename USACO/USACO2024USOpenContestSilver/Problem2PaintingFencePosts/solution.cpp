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

int di(const pair<int, int>& p1, const pair<int, int>& p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, p;
    cin >> n >> p;

    vector<pair<int, int> > posts(p);
    map<int, map<int, int> > pgrid;
    vector<int> pdist(p);

    for (int i = 0; i < p; i++) {
        cin >> posts[i].first >> posts[i].second;
        pgrid[posts[i].first][posts[i].second] = i;
    }

    pdist[0] = di(posts.front(), posts.back());

    for (int i = 1; i < p; i++) {
        pdist[i] = pdist[i - 1] + di(posts[i], posts[i - 1]);
    }

    // process the cow paths
    vector<int> brush(p);

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // clockwise
        int cw = 0;
        int wstart, wend;

        // counter clockwise
        int cc = 0;
        int cstart, cend;

        int start, end;
        if (cw < cc) {
            start = wstart;
            end = wend;
        } else {
            start = cstart;
            end = cend;
        }

        brush[start]++;
        if (start < end) {
            if (end + 1 < p) {
                brush[end + 1]--;
            }
        }
        else {
            brush[0]++;
            brush[end + 1]--;
        }
    }

    // print answer
    int last = 0;
    for (int& x : brush) {
        last += x;
        cout << last << '\n';
    }
}
