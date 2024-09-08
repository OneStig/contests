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
#define f first
#define s second

#define vpi vector<pair<int, int>>

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int nt, ns, rmax;
    cin >> nt >> ns >> rmax;

    map<int, set<int>> forest;
    vector<pair<int, int>> points(nt);

    for (auto& x : points) {
        cin >> x.f >> x.s;
        forest[x.f].insert(x.s);
    }

    array<vpi, 4> rel = {vpi(ns), vpi(ns), vpi(ns), vpi(ns)};
    for (auto& x : rel[0]) {
        cin >> x.f >> x.s;
    }
    // fixed tree is at 0, 0
    // rel[0] = robot relative to fixed tree
    // rel[1..ns] = other trees relative to 0, 0

    for (int i = 1; i < ns; i++) {
        rel[0][i].f -= rel[0][0].f;
        rel[0][i].s -= rel[0][0].s;
    }

    rel[0][0].f = -rel[0][0].f;
    rel[0][0].s = -rel[0][0].s;

    for (int r = 1; r < 4; r++) {
        for (int i = 0; i < ns; i++) {
            rel[r][i].f = rel[r - 1][i].s;
            rel[r][i].s = -rel[r - 1][i].f;
        }
    }

    int found = 0;
    int rx, ry;

    for (int fix = 0; fix < nt; fix++) {
        int fixx = points[fix].f, fixy = points[fix].s;
        for (int rot = 0; rot < 4; rot++) {
            bool exists = 1;

            for (int posi = 1; posi < ns; posi++) {
                auto pos = rel[rot][posi];
                int testx = fixx + pos.f, testy = fixy + pos.s;
                if (!forest.contains(testx) || !forest[testx].contains(testy)) {
                    exists = 0;
                    break;
                }
            }

            if (!exists) continue;
            int robotx = fixx + rel[rot][0].f, roboty = fixy + rel[rot][0].s;

            if (forest[robotx].contains(roboty)) continue;

            int inrange{};
            for (auto& pt : points) {
                if (abs(robotx - pt.f) + abs(roboty - pt.s) <= rmax) {
                    inrange++;
                }

                if (inrange > ns) break;
            }

            if (fix == 2 && rot == 0) {
                dbg(inrange);
            }

            if (inrange == ns) {
                found++;
                rx = robotx;
                ry = roboty;
            }

            if (found > 1) break;
        }

        if (found > 1) break;
    }

    if (found == 0) {
        cout << "Impossible\n";
    }
    else if (found == 1) {
        cout << rx << ' ' << ry << '\n';
    }
    else {
        cout << "Ambiguous\n";
    }
}
