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

char grid[501][501];

void solve()
{
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;

        FOR0(i, n) {
            string tin;
            cin >> tin;

            FOR0(j, m) {
                grid[i][j] = tin[j];
            }
        }

        int sol = 0;

        FOR0(i, n) {
            
            FOR0(j, m) {
                if (grid[i][j] == '.') {
                    continue;
                }

                sol++;

                int k = 0;

                while (1) {
                    k++;
                    if (i + k >= n || j + k >= m || j - k < 0) {
                        break;
                    }

                    int found = 1;

                    FOR(l, j - k, j + k + 1) {
                        if (grid[i + k][l] == '.') {
                            found = 0;
                            break;
                        }
                    }

                    if (found) {
                        sol++;
                        continue;
                    }

                    break;
                }
            }
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