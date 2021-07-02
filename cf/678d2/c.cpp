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

// End of template


ll fact(ll in) {
    ll s = 1;
    for (int i = 2; i <= in; i++) {
        s *= i % 1000000007;
    }

    return s;
}

void solve()
{
    int n, x, pos;
    cin >> n >> x >> pos;

    int l = 0;
    int r = n;

    int less = 0;
    int greater = 0;

    while (l < r) {
        int mid = (l + r) / 2;

        if (mid <= pos) {
            less++;
            l = mid + 1;
        }
        else {
            greater++;
            r = mid;
        }
    }

    less--;

    ll comb = 0;
    comb += fact(n - x) / max(fact(n - x - greater), (ll)1);
    comb += fact(x - 1) / max(fact(x - 1 - less), (ll)1);

    ll sol = fact(n - less - greater - 1) * comb % 1000000007;

    cout << sol << endl;
}

int main()
{
    ios_base::sync_with_stdio(); cin.tie(0); freopen("test.in", "r", stdin);
    solve();
    return 0;
}