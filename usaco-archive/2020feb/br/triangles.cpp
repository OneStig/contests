#define problemname "triangles"

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using db = double;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<string>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR0(i, a) FOR(i, 0, a)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define RFOR0(i, a) ROF(i, 0, a)

#define pb push_back;

// End of template

void solve()
{
    int n;
    vpi xy;
    cin >> n;

    ll sol = 0;

    FOR0(i, n) {
        int x, y;
        cin >> x >> y;
        xy.push_back(make_pair(x, y));
    }

    FOR0(i, n) {
        int xm = 0;
        int ym = 0;

        FOR0(j, n) {
            if (xy[i].second == xy[j].second) {
                xm = abs(xy[i].first - xy[j].first);
                FOR0(k, n) {
                    if (xy[i].first == xy[k].first) {
                        ym = abs(xy[i].second - xy[k].second);
                    }

                    sol = max(sol, (ll)xm * ym);
                }
            }
        }
    }

    cout << sol << endl;
}

int main()
{
    ios_base::sync_with_stdio(); cin.tie(0);
    freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);
    solve();
    return 0;
}