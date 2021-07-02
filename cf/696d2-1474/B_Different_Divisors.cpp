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
#define RFOR0(i, a) RFOR(i, 0, a)

// End of template

bool pr(int x)
{
    int i;
    for (i = 2; i <= x / 2; i++) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

int next(int a) {
    for (int i = a; 1; i++) {
        if (pr(i)) {
            return i;
        }
    }
}

void solve()
{
    int t;
    cin >> t;
    while (t--) {
        int a;
        cin >> a;
        int f = next(a + 1);
        f *= next(f + a);
        cout << f << endl;
    }
}

int main()
{
    // ios_base::sync_with_stdio(); cin.tie(0); freopen("test.in", "r", stdin);
    solve();
    return 0;
}