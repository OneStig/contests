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

typedef array<int, 2> pt;

const ld INF = 1e10;
int n;
pt stars[301];

ld dist(pt p1, pt p2) {
    return sqrt((p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]));
}

int tri(pt p1, pt p2, pt p3) {
    return abs(p1[0] * (p2[1] - p3[1]) + p2[0] * (p3[1] - p1[1]) + p3[0] * (p1[1] - p2[1]));
}

int cross(pt a, pt p1, pt p2) {
    return (p2[0] - p1[0]) * (a[1] - p1[1]) - (p2[1] - p1[1]) * (a[0] - p1[0]);
}

void solve() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> stars[i][0] >> stars[i][1];
    }

    pt b;
    cin >> b[0] >> b[1];

    ld ans{INF};

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {

                if (
                    dist(stars[i], stars[j]) == dist(stars[i], b) + dist(stars[j], b) || 
                    dist(stars[j], stars[k]) == dist(stars[j], b) + dist(stars[k], b) ||
                    dist(stars[k], stars[i]) == dist(stars[k], b) + dist(stars[i], b)
                ) {
                    continue;
                }

                int totarea = tri(stars[i], stars[j], stars[k]);
                int area1 = tri(b, stars[j], stars[k]);
                int area2 = tri(stars[i], b, stars[k]);
                int area3 = tri(stars[i], stars[j], b);

                if (totarea != 0 && totarea == area1 + area2 + area3) {

                    ans = min(ans, 
                        (dist(stars[i], stars[j])) +
                        (dist(stars[j], stars[k])) +
                        (dist(stars[k], stars[i]))
                    );
                }
            }
        }
    }

    // check if point lies on edges.

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((dist(stars[i], stars[j])) !=
                (dist(b, stars[i])) +
                (dist(b, stars[j]))) continue;

            ld left{INF}, right{INF};

            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;

                int cp = cross(stars[k], stars[i], stars[j]);
                ld curdist = (dist(stars[i], stars[k])) +
                            (dist(stars[j], stars[k]));

                if (cp < 0) {
                    left = min(left, curdist);
                }
                else if (cp > 0) {
                    right = min(right, curdist);
                }
            }

            ans = min(ans, left + right);
        }
    }

    if (ans < INF) {
        cout << fixed << setprecision(15) << ans << '\n';
    }
    else {
        cout << "IMPOSSIBLE\n";
    }
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
