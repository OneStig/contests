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

ld dist(pt p1, pt p2) {
    return sqrt((p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]));
}

int cross(pt a, pt p1, pt p2) {
    return (p2[0] - p1[0]) * (a[1] - p1[1]) - (p2[1] - p1[1]) * (a[0] - p1[0]);
}

void solve() {
    int n;
    cin >> n;

    vector<pt> stars(n);

    for (int i = 0; i < n; i++) {
        cin >> stars[i][0] >> stars[i][1];
    }

    pt b;
    cin >> b[0] >> b[1];

    ld ans{INF};

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (cross(b, stars[i], stars[j]) == 0 ||
                    cross(b, stars[j], stars[k]) == 0 ||
                    cross(b, stars[k], stars[i]) == 0) {
                    continue;
                }

                if (cross(stars[i], stars[j], stars[k]) == 0) continue;

                int a1 = cross(b, stars[i], stars[j]);
                int a2 = cross(b, stars[j], stars[k]);
                int a3 = cross(b, stars[k], stars[i]);

                a1 /= abs(a1);
                a2 /= abs(a2);
                a3 /= abs(a3);

                if (a1 == a2 && a2 == a3) {
                    ld testans = 
                        (dist(stars[i], stars[j])) +
                        (dist(stars[j], stars[k])) +
                        (dist(stars[k], stars[i]));

                    if (ans == INF) {
                        ans = testans;
                    }
                    else {
                        ans = min(ans, testans);
                    }
                }
            }
        }
    }

    // check if point lies on edges.

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cross(b, stars[i], stars[j]) != 0) continue;

            if (dist(stars[i], b) > dist(stars[i], stars[j]) || dist(stars[j], b) > dist(stars[i], stars[j])) continue;

            ld left{INF}, right{INF};

            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;

                int cp = cross(stars[k], stars[i], stars[j]);
                ld curdist = (dist(stars[i], stars[k])) +
                            (dist(stars[j], stars[k]));

                if (cp < 0) {
                    if (left == INF) {
                        left = curdist;
                    }
                    else {
                        left = min(left, curdist);
                    }
                }
                else if (cp > 0) {
                    if (right == INF) {
                        right = curdist;
                    }
                    else {
                        right = min(right, curdist);
                    }
                }
            }

            if (left != INF && right != INF) {
                if (ans == INF) {
                    ans = left + right;
                }
                else {
                    ans = min(ans, left + right);
                }
            }
        }
    }

    if (ans != INF) {
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
