#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef int uci;
#define int long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e18;
const int MAX_K = 1e9;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    vector<int> dtable(60);

    for (int j = 2; j < 60; j++) {
        dtable[j] = ceil(pow(MAX_N, (ld)1 / j));
    }

    while (t--) {
        int n;
        cin >> n;

        bool good = 0;
        for (int d = 2; d < 60; d++) {
            // let's binary search on different k to see if it is reachable
            int l = 2, r = dtable[d];
            while (l <= r) {
                int k = (r - l) / 2 + l;
                int last = 1, test = 1;

                bool nogood = 0;
                for (int i = 0; i < d; i++) {
                    if (test >= n || n / last < k || n / k < last) {
                        nogood = 1;
                        break;
                    }

                    last = last * k;
                    test += last;
                }

                if (test == n && !nogood) {
                    dbg(n, k, d, last, test);
                    good = 1;
                    break;
                }

                if (test > n || nogood) {
                    r = k - 1;
                }
                else {
                    l = k + 1;
                }
            }

            if (good) break;
        }

        cout << (good ? "YES" : "NO") << '\n';
    }
}

// idea: for each case, we cannot repeat to depth more than 60
// since k at min is 2, at 2^60 > 1e18
