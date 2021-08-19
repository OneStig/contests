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
        int n, x;
        cin >> n >> x;
        
        vi nums;
        vi fix;

        FOR0(i, n) {
            int y;
            cin >> y;
            nums.push_back(y);

            if (i != 0 && y < nums[i - 1]) {
                fix.push_back(i - 1);
            }
        }

        int ans = 0;

        int np = 0;

        for (int i = 0; i < fix.size(); i++) {
            int b = 1;

            for (int j = 0; j <= fix[i]; j++) {
                if (nums[j] > x) {
                    b = 0;
                    ans += fix[i] - j + 1;

                    break;
                }
            }

            if (b) {
                np = 1;
                break;
            }
            
            x = nums[fix[i]];
        }

        if (np) {
            cout << -1 << endl;
        }
        else {
            cout << ans << endl;
        }
    }
}

int main()
{
    // ios_base::sync_with_stdio(); cin.tie(0); freopen("test.in", "r", stdin);
    solve();
    return 0;
}