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
        deque<pair<int,int>> vec(n, make_pair(0, 0));
        FOR0(i, n) {
            int tmp;
            cin >> tmp;
            vec[i].first = tmp;
        }

        FOR0(i, n) {
            int tmp;
            cin >> tmp;
            vec[i].second = tmp;
        }

        sort(vec.begin(), vec.end());
        reverse(vec.begin(), vec.end());

        int ptot = 0;

        while (vec.size()) {
            if (vec[0].first > vec[0].second + ptot) {
                ptot += vec[0].second;
                vec.pop_front();
            }
            else {
                break;
            }
        }

        FOR0(i, vec.size()) {
            ptot = max(ptot, vec[i].first);
        }

        cout << ptot << endl;
    }
}

int main()
{
    // ios_base::sync_with_stdio(); cin.tie(0); freopen("test.in", "r", stdin);
    solve();
    return 0;
}