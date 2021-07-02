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
        vi nums(n);

        FOR0(i, n) {
            cin >> nums[i];
        }

        sort (nums.begin(), nums.end());

        long long al = 0;
        long long bob = 0;

        int tu = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (tu == 0) {
                tu = 1;

                if (nums[i] % 2 == 0) {
                    al += nums[i];
                }
            }
            else {
                tu = 0;

                if (nums[i] % 2 == 1) {
                    bob += nums[i];
                }
            }
        }

        if (bob > al) {
            cout << "Bob" << endl;
        }
        else if (al > bob) {
            cout << "Alice" << endl;
        }
        else {
            cout << "Tie" << endl;
        }
    }
}

int main()
{
    // ios_base::sync_with_stdio(); cin.tie(0); freopen("test.in", "r", stdin);
    solve();
    return 0;
}