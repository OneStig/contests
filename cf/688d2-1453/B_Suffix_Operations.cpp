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
        int n;
        cin >> n;
        vl nums(n);

        FOR0(i, n) {
            cin >> nums[i];
        }

        ll dif = abs(nums[1] - nums[0]);
        int s = 0;

        if (abs(nums[n - 1] - nums[n - 2]) > dif) {
            dif = abs(nums[n - 1] - nums[n - 2]);
            s = n - 1;
        }

        FOR0(i, n) {
            
            if (i != 0 && i != n - 1) {
                ll tmp = abs(nums[i] - nums[i - 1]) + abs(nums[i] - nums[i + 1]) - abs(nums[i + 1] - nums[i - 1]);
                
                if (tmp > dif) {
                    dif = tmp;
                    s = i;
                }
            }
        }

        if (s == 0) {
            nums[0] = nums[1];
        }
        else {
            nums[s] = nums[s - 1];
        }

        ll sol = 0;

        for (int i = n - 1; i > 0; i--) {
            sol += abs(nums[i] - nums[i - 1]);
        }

        cout << sol << endl;
    }
}

int main()
{
    // ios_base::sync_with_stdio(); cin.tie(0); freopen("test.in", "r", stdin);
    solve();
    return 0;
}