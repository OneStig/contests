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

void solve()
{
    int t;
    cin >> t;
    while (t--) {
        ll sum = 0;
        int n;
        cin >> n;
        vi nums;

        FOR0(i, n) {
            int mp;
            cin >> mp;
            sum += mp;
            nums.push_back(mp);
        }

        RFOR(i, 1, n + 1) {
            if (sum % i == 0)  {
                int targ = sum / i;
                int sol = 0;
                int insum = 0;
                int found = 1;
                for (int j = 0; j < n; j++) {
                    insum += nums[j];

                    if (insum == targ) {
                        insum = 0;
                        sol++;
                    }

                    if (insum > targ) {
                        found = 0;
                        break;
                    }
                }

                if (found && insum == 0 && sol == i) {
                    cout << n - sol << endl;
                    break;
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