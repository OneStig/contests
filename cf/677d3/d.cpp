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
        vi nums;

        int l = 1;
        int s = 0;
        FOR0(i, n) {
            int k;
            cin >> k;

            if (i == 0) {
                s = k;
            }
            else if (s != k) {
                l = 0;
            }

            nums.push_back(k);
        }

        if (l) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;

        int hub = nums[0];

        int hhub = -1;
        int hubpos = -1;

        FOR(i, 1, n) {
            if (nums[i] != hub) {
                cout << 1 << " " << i + 1 << endl;

                if (hubpos == -1) {
                    hubpos = i + 1;
                    hhub = nums[i];
                }
            }
        }

        FOR(i, 1, n) {
            if (nums[i] == hub) {
                cout << hubpos << " " << i + 1 << endl;
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