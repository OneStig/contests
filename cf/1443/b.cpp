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
        int a, b;
        cin >> a >> b;

        string nums;
        cin >> nums;

        int n = nums.length();
        
        int streaks = 0;
        int place = 0;
        int last = '0';


        FOR0(i, n) {
            if (last == '1' && nums[i] == '0') {
                streaks++;
            }

            last = nums[i];
        }

        int zs = 0;
        int fz = 0;

        FOR0(i, n) {
            if (nums[i] == '1' && !fz) {
                fz = 1;
                zs = 0;
            }
            else if (nums[i] == '1' && zs && fz) {
                if (zs * b < a) {
                    streaks--;
                    place += zs;
                }

                zs = 0;
            }

            if (nums[i] == '0') {
                zs++;
            }
        }

        if (nums[n - 1] == '1') {
            streaks++;
        }

        cout << (place * b + streaks * a) << endl;
    }
}

int main()
{
    // ios_base::sync_with_stdio(); cin.tie(0); freopen("test.in", "r", stdin);
    solve();
    return 0;
}