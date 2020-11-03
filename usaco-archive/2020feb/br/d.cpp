
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
    
    while(t--) {
        int n;
        cin >> n;
 
        vi nums(n, 0);
 
        FOR0(i, n) {
            cin >> nums[i];
        }

        int l = nums[0];
        int r = 0;

        FOR(i, 1, n) {
            if (nums[i] - nums[i - 1] < 0) {
                l -= nums[i] - nums[i - 1];
            }
            else {
                r += nums[i] - nums[i - 1];
            }
        }

        if (l < 0 || r > nums[n - 1]) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
    }
}
 
int main()
{
    // ios_base::sync_with_stdio(); cin.tie(0); freopen("test.in", "r", stdin);
    solve();
    return 0;
}