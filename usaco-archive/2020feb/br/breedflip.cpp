#define problemname "breedflip"

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
    string a, b;
    cin >> n >> a >> b;

    int s = 0;
    int last = 0;

    FOR0(i, n) {
        if (a[i] != b[i]) {
            last = 1;
        }
        else if (a[i] == b[i] && last) {
            s++;
            last = 0;
        }
    }

    if (a[n - 1] != b[n - 1]) {
        s++;
    }

    cout << s << endl;
}

int main()
{
    ios_base::sync_with_stdio(); cin.tie(0);
    freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);
    solve();
    return 0;
}