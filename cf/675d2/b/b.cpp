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

int nums[100][100];

int main()
{
    //ifstream cin("test.in");

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        ll sol = 0;

        FOR0(i, n)
        {
            FOR0(j, m)
            {
                cin >> nums[i][j];
            }
        }

        FOR0(i, n / 2)
        {
            FOR0(j, m / 2)
            {
                ll avg = nums[i][j] + nums[n - i - 1][j] + nums[i][m - j - 1] + nums[n - i - 1][m - j - 1];

                if (avg % 4 > 2) {
                    avg /= 4;
                    avg++;
                }
                else {
                    avg /= 4;
                }

                sol += abs(nums[i][j] - avg);
                sol += abs(nums[n - i - 1][j] - avg);
                sol += abs(nums[i][m - j - 1] - avg);
                sol += abs(nums[n - i - 1][m - j - 1] - avg);
            }
        }

        if (n % 2)
        {
            FOR0(k, m / 2)
            {
                sol += abs(nums[n / 2][k] - nums[n / 2][m - k - 1]);
            }
        }

        if (m % 2)
        {
            FOR0(k, n / 2)
            {
                sol += abs(nums[k][m / 2] - nums[n - k - 1][m / 2]);
            }
        }

        cout << sol << endl;
    }
}