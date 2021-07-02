#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vc = vector<char>;
using pii = pair<int, int>;
using vpii = vector<pii>;

#define FORI(i, a, b, p) for (int i = a; i < b; i += p)
#define FOR(i, a, b) FORI(i, a, b, 1)
#define F0R(i,b) FOR(i, 0, b)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 998244353

int t;
int a[3000];

int main() {
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        F0R(i, n) cin >> a[i];

        int sum = 0;
        F0R(i, n) sum += a[i];

        int psize = n;
        while (psize > 1) {
            if (sum % psize != 0) {
                psize--;
                continue;
            }
            int val = sum / psize;
            int p = 0;
            int vals = 0;
            bool uneven = false;
            F0R(i, n) {
                p += a[i];
                if (p == val) {
                    p = 0;
                    vals++;
                }
                if (p > val) {
                    uneven = true;
                    break;
                }
            }
            if (vals == psize && !uneven) {
                break;
            }
            psize--;
        }
        cout << n - psize << '\n';
    }
}