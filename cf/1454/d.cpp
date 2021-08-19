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

int freq[100000];

void solve()
{
    int t;
    cin >> t;
    while(t--) {
        ll n;
        ll tmp;
        cin >> n;
        tmp = n;

        memset(freq, 0, sizeof(freq));

        while (tmp % 2 == 0) {
            freq[2]++;
            tmp /= 2;
        }

        int sol = freq[2];
        ll nn = 2;

        for (int i = 3; i <= sqrt(tmp); i += 2) {
            while (tmp % i == 0) {
                sol = max(sol, ++freq[i]);

                if (freq[i] == sol) {
                    nn = i;
                }

                tmp /= i;
            }
        }

        if (sol <= 1) {
            cout << 1 << endl << n << endl;
            continue;
        }

        cout << sol << endl;

        FOR(i, 1, sol) {
            cout << nn << " ";
        }

        cout << fixed << (ll)(n / pow(nn, (sol - 1))) << endl;
    }
}

int main()
{
    // ios_base::sync_with_stdio(); cin.tie(0); freopen("test.in", "r", stdin);
    solve();
    return 0;
}