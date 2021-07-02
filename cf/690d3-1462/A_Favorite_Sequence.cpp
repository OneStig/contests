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

int nums[301];
int restor[602];

void solve()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        FOR0(i, n) {
            cin >> nums[i];
        }

        FOR0(i, n) {
            restor[i * 2] = nums[i];
        }

        int c = (n / 2) * 2 - 1;

        for (int i = (n + 1) / 2; i < n; i++) {
            restor[c] = nums[i];
            c -= 2;
        }

        FOR0(i, n) {
            if (i != 0) {
                cout << " ";
            }

            cout << restor[i];
        }

        cout << endl;
    }
}

int main()
{
    // ios_base::sync_with_stdio(); cin.tie(0); freopen("test.in", "r", stdin);
    solve();
    return 0;
}