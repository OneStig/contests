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
        int n;
        cin >> n;

        string a;
        
        cin >> a;

        string s;
        s.assign(a);

        int sol = 0;
        int df = 0;

        FOR(i, 1, n) {
            if (s[i] == s[i - 1]) {
                s[i] = (s[i] == '1') ? '0' : '1';

                if (i < n - 1 && s[i + 1] == s[i - 1]) {
                    sol++;
                }
                else {
                    df++;;
                    if (i < n - 1) {
                        s[i + 1] = s[i - 1];
                    }
                }          
            }
        }

        sol += df / 2 + df % 2;

        s.assign(a);
        df = 0;

        int nsol = 0;

        s[0] = (s[0] == '1') ? '0' : '1';

        if (s[0] != s[1]) {
            df++;
        }
        else {
            nsol++;
        }

        FOR(i, 1, n) {
            if (s[i] == s[i - 1]) {
                s[i] = (s[i] == '1') ? '0' : '1';

                if (i < n - 1 && s[i + 1] == s[i - 1]) {
                    nsol++;
                }
                else {
                    df++;;
                    if (i < n - 1) {
                        s[i + 1] = s[i - 1];
                    }
                }          
            }
        }

        nsol += df / 2 + df % 2;

        cout << min(sol, nsol) << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(); cin.tie(0); freopen("test.in", "r", stdin);
    solve();
    return 0;
}