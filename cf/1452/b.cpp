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
        int n, tmp;
        cin >> n;

        int m = 0;
        int m2 = 0;
        int s = 0;
        vi nums;

        FOR0(i, n) {
            cin >> tmp;
            nums.push_back(tmp);
            if (tmp > m) {
                m = tmp;
                s = i;
            }
        }

        ll sd = 0;
        ll sd2 = 0;

        FOR0(i, n) {
            if (i != s) {
                m2 = max(m2, nums[i]);
                sd += m - nums[i];
            }
        }

        FOR0(i, n) {
            if (i != s) {
                sd2 += m2 - nums[i];
            }
        }

        ll s1 = sd - m;
        while (s1 < 0) {
            s1 += n - 1;
        }

        ll s2 = sd2 - m;
        while (s2 < 0) {
            s2 += n - 1;
        }

        cout << max(s1, s2) << endl;
    }
}

int main()
{
    // ios_base::sync_with_stdio(); cin.tie(0); freopen("test.in", "r", stdin);
    solve();
    return 0;
}