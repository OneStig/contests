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

int times[201];
int taken[201];

void solve()
{
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;

        memset(times, 0, sizeof(times));
        memset(taken, 0, sizeof(taken));

        int sol = 0;

        FOR0(i, n) {
            int t;
            cin >> t;

            times[t]++;
        }

        FOR0(i, n + 1) {
            while (times[i]--) {
                FOR(j, 1, 201) {
                    if ((i + j < 201 && !taken[i + j]) || (i - j >= 0 && !taken[i - j])) {
                        taken[i + j] = 1;
                        sol += j;
                        break;
                    }
                }
            }
        }

        cout << sol << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(); cin.tie(0); freopen("test.in", "r", stdin);
    solve();
    return 0;
}