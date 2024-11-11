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

struct Point {
    typedef Point P;
    int x, y;
    explicit Point(int x=0, int y=0) : x(x), y(y) {}
    int cross(const P p) const { return x*p.y - y*p.x; }
};

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<Point> poly(n);
    for (Point& p : poly) {
        cin >> p.x >> p.y;
    }
    poly.push_back(poly[0]);

    // if clockwise reverse(all(poly))

    int area = 0;
    for (int i = 0; i < n; i++) {
        Point a = poly[i], b = poly[i + 1];

        area += (b.x - a.x) * (b.y + a.y);
    }

    // dbg(area);

    if (area > 0) {
        reverse(all(poly));
    }

    Point bug, targ;
    cin >> bug.x >> bug.y >> targ.x >> targ.y;

    targ.x -= bug.x;
    targ.y -= bug.y;

    auto check = [&](int e) -> string {
        Point vec(poly[e + 1].x - poly[e].x, poly[e + 1].y - poly[e].y);
        int cp = vec.cross(targ);

        if (cp == 0) {
            return "?";
        }
        if (cp > 0) {
            return "inside";
        }
        return "outside";
    };

    vector<int> tocheck;
    for (int i = 0; i < n; i++) {
        int first = (bug.y - poly[i].y) * (poly[i + 1].x - poly[i].x);
        int second = (bug.x - poly[i].x) * (poly[i + 1].y - poly[i].y);

        int mnx = min(poly[i].x, poly[i + 1].x);
        int mxx = max(poly[i].x, poly[i + 1].x);
        int mny = min(poly[i].y, poly[i + 1].y);
        int mxy = max(poly[i].y, poly[i + 1].y);

        if (first == second and bug.x >= mnx and bug.x <= mxx and bug.y >= mny and bug.y <= mxy) {
            tocheck.push_back(i);
        }
    }

    string ans = check(tocheck[0]);

    for (int i = 1; i < sz(tocheck); i++) {
        string nxt = check(tocheck[i]);
        if (nxt != ans) {
            ans = "?";
            break;
        }
    }

    cout << ans << '\n';
}
