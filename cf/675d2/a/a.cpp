#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using db = double; 
 
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;
 
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>; 
using vs = vector<string>;
using vpi = vector<pi>;
using vpl = vector<pl>; 
using vpd = vector<pd>;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR0(i,a) FOR(i,0,a)
#define RFOR(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define RFOR0(i,a) ROF(i,0,a)

// End of template

int main()
{
    // ifstream cin("test.in");

    int t;
    cin >> t;

    while (t--) {
        vi sizes;
        FOR0(i, 3) {
            int n;
            cin >> n;
            sizes.push_back(n);
        }
        sort(sizes.begin(), sizes.end());
        cout << sizes[0] + sizes[2] << endl;
    }
}