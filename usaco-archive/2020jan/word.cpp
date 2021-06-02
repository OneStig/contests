/*
ID: stevenh6
TASK: word
LANG: C++
*/

#define problemname "word"

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

#define pb push_back;

// End of template

void solve()
{
    int n, k;
    string s;
    cin >> n >> k;

    int c = 0;

    while (n--) {
        cin >> s;

        if (c + s.length() > k) {
            cout << endl;
            c = 0;
        }

        if (c > 0) {
            cout << " ";
        }

        cout << s;

        c += s.length();
    }

    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(); cin.tie(0);
    freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);
    solve();
    return 0;
}