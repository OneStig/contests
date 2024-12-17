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

#define mv pair<int, pair<int, int>>

const int INF = 1e12;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector<string> g;
    string x;
    while (cin >> x) {
        g.emplace_back(x);
    }

    int R = sz(g);
    int C = sz(g[0]);


    vector<int> dr = {0, -1, 0, 1};
    vector<int> dc = {1, 0, -1, 0};

    vector<vector<int>> cost(R * C, vector<int>(4, INF));

    int sr, sc, er, ec;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (g[i][j] == 'S') {
                sr = i;
                sc = j;
            }
            else if (g[i][j] == 'E') {
                er = i;
                ec = j;
            }
        }
    }

    cost[sr * C + sc][0] = 0;

    priority_queue<mv, vector<mv>, greater<mv>> q;
    q.push({0, {sr * C + sc, 0}});

    while (sz(q)) {
        auto cur = q.top();
        int curr = cur.second.first / C;
        int curc = cur.second.first % C;

        q.pop();
    
        if (cur.first != cost[cur.second.first][cur.second.second]) continue;
    
        int rot = 1000 + cur.first;
        if (rot < cost[cur.second.first][(cur.second.second + 1) % 4]) {
            q.push({rot, {cur.second.first, (cur.second.second + 1) % 4}});
            cost[cur.second.first][(cur.second.second + 1) % 4] = rot;
        }

        int rot2 = 1000 + cur.first;
        if (rot2 < cost[cur.second.first][(cur.second.second + 3) % 4]) {
            q.push({rot2, {cur.second.first, (cur.second.second + 3) % 4}});
            cost[cur.second.first][(cur.second.second + 3) % 4] = rot2;
        }

        int go = 1 + cur.first;
        int gr = curr + dr[cur.second.second];
        int gc = curc + dc[cur.second.second];
    
        if (gr >= 0 && gr < R && gc >= 0 && gc < C && g[gr][gc] != '#' &&
            go < cost[gr * C + gc][cur.second.second]) {
            cost[gr * C + gc][cur.second.second] = go;
            q.push({go, {gr * C + gc, cur.second.second}});
        }
    }

    int ans = INF;
    for (int i = 0; i < 4; i++) {
        ans = min(ans, cost[er * C + ec][i]);
    }


    dbg(ans);

    vector<vector<int>> invcost(R * C, vector<int>(4, INF));
    swap(sr, er);
    swap(sc, ec);

    invcost[sr * C + sc][0] = 0;
    invcost[sr * C + sc][1] = 0;
    invcost[sr * C + sc][2] = 0;
    invcost[sr * C + sc][3] = 0;

    q = priority_queue<mv, vector<mv>, greater<mv>>();
    q.push({0, {sr * C + sc, 0}});
    q.push({0, {sr * C + sc, 1}});
    q.push({0, {sr * C + sc, 2}});
    q.push({0, {sr * C + sc, 3}});

    while (sz(q)) {
        auto cur = q.top();
        int curr = cur.second.first / C;
        int curc = cur.second.first % C;

        q.pop();
    
        if (cur.first != invcost[cur.second.first][cur.second.second]) continue;
    
        int rot = 1000 + cur.first;
        if (rot < invcost[cur.second.first][(cur.second.second + 1) % 4]) {
            q.push({rot, {cur.second.first, (cur.second.second + 1) % 4}});
            invcost[cur.second.first][(cur.second.second + 1) % 4] = rot;
        }

        int rot2 = 1000 + cur.first;
        if (rot2 < invcost[cur.second.first][(cur.second.second + 3) % 4]) {
            q.push({rot2, {cur.second.first, (cur.second.second + 3) % 4}});
            invcost[cur.second.first][(cur.second.second + 3) % 4] = rot2;
        }

        int go = 1 + cur.first;
        int gr = curr + dr[(cur.second.second + 2) % 4];
        int gc = curc + dc[(cur.second.second + 2) % 4];
    
        if (gr >= 0 && gr < R && gc >= 0 && gc < C && g[gr][gc] != '#' &&
            go < invcost[gr * C + gc][cur.second.second]) {
            invcost[gr * C + gc][cur.second.second] = go;
            q.push({go, {gr * C + gc, cur.second.second}});
        }
    }

    int ans2 = 0;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            int cand = INF;
            for (int dir = 0; dir < 4; dir++) {
                cand = min(cand, cost[r * C + c][dir] + invcost[r * C + c][dir]);
            }

            ans2 += cand == ans;
        }
    }

    dbg(ans2);
}