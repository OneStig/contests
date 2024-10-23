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

const ld MX_ERR = 1e-5;

ld dist(ld x1, ld y1, ld x2, ld y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> orcs(n);
    for (auto& o : orcs) {
        cin >> o.first >> o.second;
        // dbg(o);
    }

    bool foundans = 0;
    ld l = 0, r = 2000;
    while (r - l > MX_ERR) {
        ld rad = (r + l) / 2;
        // dbg(l, r, rad);

        map<ld, pair<int, int>> gaps;

        for (auto& o : orcs) {
            ld x = o.first, y = o.second;
            ld theta;

            ld d = dist(0, 0, x, y);

            if (x != 0) {
                theta = atan(y / x);
            }
            else if (y > 0) {
                theta = (ld)3 * M_PI / 2;
            }
            else {
                theta = M_PI / (ld)2;
            }

            if (2 * rad < d) {
                continue;
            }

            ld alpha = abs(acos(d / ((ld)2 * rad)));
            ld lb = theta - alpha * 2, rb = theta + alpha * 2;

            if (lb < 0) {
                lb += 2 * M_PI;
            }

            if (rb > 2 * M_PI) {
                rb -= 2 * M_PI;
            }

            // dbg(o, alpha, theta, d, rad, lb, rb);

            if (lb <= rb) {
                gaps[lb].first++;
                gaps[rb].second--;
            }
            else {
                gaps[0].first++;
                gaps[rb].second--;

                gaps[lb].first++;
                gaps[2 * M_PI].second--;
            }
        }

        // dbg(gaps);

        // compress points if they are too close
        map<ld, pair<int, int>> newpts;
        ld last = -1000;
        for (auto [pt, fs] : gaps) {
            if (pt - last < MX_ERR) {
                newpts.rbegin()->second.first += fs.first;
                newpts.rbegin()->second.second += fs.second;
            }
            else {
                newpts[pt] = fs;
            }
        }

        bool good = 0;

        int pfx{};
        for (auto [pt, fs] : newpts) {
            pfx += fs.first;

            if (pfx >= k) {
                foundans = 1;
                good = 1;
                break;
            }

            pfx -= fs.second;
        }

        if (good) {
            r = rad;
        }
        else {
            l = rad;
        }
    }

    if (!foundans) {
        cout << "-1\n";
    }
    else {
        cout << fixed << setprecision(10) << l << '\n';
    }
}
