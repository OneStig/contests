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

ll an[26];
ll bn[26];

void solve()
{
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string a, b;
        cin >> a >> b;

        int front = 26;

        memset(an, 0, sizeof(an));
        memset(bn, 0, sizeof(bn));

        FOR0(i, n) {
            an[a[i] - 'a']++;
            bn[b[i] - 'a']++;
        }

        int no = 1;

        RFOR(i, 0, 26) {
            FOR(j, i, front) {
                if (i == j) {
                    int tmp = min(an[i], bn[j]);
                    an[i] -= tmp;
                    bn[j] -= tmp;
                }
                else {
                    if (an[i] >= k && bn[j] >= k) {
                        int tm = min(an[i] / k, bn[j] / k);
                        an[i] -= k * tm;
                        bn[j] -= k * tm;
                    }
                }

                if (an[i] == 0) {
                    break;
                }
            }

            if (an[i] > 0) {
                cout << "No" << endl;
                no = 0;
                break;
            }
        }

        if (no) {
            cout << "Yes" << endl;
        }
    }
}

int main()
{
    // ios_base::sync_with_stdio(); cin.tie(0); freopen("test.in", "r", stdin);
    solve();
    return 0;
}