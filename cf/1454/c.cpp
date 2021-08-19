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

int freq[200001];

void solve()
{
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        memset(freq, 0, sizeof(freq));

        vi nums;

        int tmp;
        cin >> tmp;
        nums.push_back(tmp);

        int nn = 1;

        FOR(i, 1, n) {
            cin >> tmp;
            if (tmp != nums[nn - 1]) {
                nums.push_back(tmp);
                freq[tmp]++;
                nn++;
            }
        }

        freq[nums[nn - 1]]--;

        int sol = INT_MAX;

        FOR0(i, nn) {
            sol = min(sol, freq[nums[i]] + 1);
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