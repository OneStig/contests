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
        vi left(n, 0);
        vi right(n, 0);

        FOR0(i, n) {
            cin >> nums[i];
        }

        left[0] = nums[0];
        right[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            if (left[i - 1] > nums[i]) {
                left[i] = left[i - 1] - nums[i];
            }
            else {
                left[i] = left[i - 1];
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (right[i + 1] > nums[i]) {
                right[i] = right[i + 1] - nums[i];
            }
            else {
                right[i] = right[i + 1];
            }
        }

        int yes = 1;

        for (int i = 1; i < n - 1; i++) {
            if (right[i] + left[i] < nums[i]) {
                yes = 0;
                break;
            }
        }

        if (yes) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(); cin.tie(0); freopen("test.in", "r", stdin);
    solve();
    return 0;
}