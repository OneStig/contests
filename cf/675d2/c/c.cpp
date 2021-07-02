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

int main()
{
    ll sol = 0;

    string n;
    cin >> n;

    FOR0(i, n.length())
    {
        FOR(j, 1, n.length() - i + 1)
        {
            if (!(i == 0 && j == n.length()))
            {
                string ad = "";
                if (n.substr(0, i) != "") {
                    ad = n.substr(0, i);
                }

                if (i != n.length() - 1 && n.substr(i + j, n.length() - i - j) != "") {
                    ad += n.substr(i + j, n.length() - i - j);
                }

                sol += stoll(ad) % 1000000007;
            }
        }
    }

    cout << sol << endl;
}