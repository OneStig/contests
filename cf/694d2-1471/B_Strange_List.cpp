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

        map<int, int> cache;

        cin >> n >> x;

        vi nums(n);
        queue<pi> suff;

        long long sol = 0;

        FOR0(i, n) {
            cin >> nums[i];
            sol += nums[i];
        }

        int b = 1;

        FOR0(i, n) {
            if (nums[i] % x != 0) {
                b = 0;
                break;
            }

            suff.push(make_pair(nums[i] / x, x));
        }

        while (!suff.empty()) {
            pi cur = suff.front();

            if (cur.first % x != 0) {
                b = 0;
            }

            if (b) {
                suff.push(make_pair(cur.first / x, cur.second * x));
            }

            sol += cur.first * cur.second;

            suff.pop();
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