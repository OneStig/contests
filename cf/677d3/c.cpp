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

void solve()
{
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vi a;

        int l = 1;
        int s = 0;

        int m = 0;

        FOR0(i, n) {
            int k;
            cin >> k;

            m = max(m, k);
            
            if (i == 0) {
                s = k;
            }
            else {
                if (k != s) {
                    l = 0;
                }
            }

            a.push_back(k);
        }

        if (l) {
            cout << -1 << endl;
        }
        else {
            FOR0(i, n) {
                if (a[i] == m) {
                    if (i > 0 && a[i - 1] < m) {
                        cout << i + 1 << endl;
                        break;
                    }

                    if (i < n - 1 && a[i + 1] < m) {
                        cout << i + 1 << endl;
                        break;
                    }
                }
            }
        }
    }
}

int main()
{
    // ios_base::sync_with_stdio(); cin.tie(0); freopen("test.in", "r", stdin);
    solve();
    return 0;
}