#include <bits/stdc++.h>
#include <sys/_types/_off_t.h>

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

const int MAX_B = 32;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        vector<array<int, MAX_B>> pfx(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pfx[i] = pfx[i - 1];

            int cur = a[i];
            for (int b = 0; b < MAX_B; b++) {
                if (cur % 2) {
                    pfx[i][b]++;
                }
                cur >>= 1;
            }
        }

        int ans{};

        for (int y = 1; y <= n; y++) {
            int sig = -1;
            for (int b = MAX_B - 1; b >= 0; b--) {
                if (a[y] & (1 << b)) {
                    sig = b;
                    break;
                }
            }

            int left = pfx[y][sig], right = pfx[n][sig] - pfx[y][sig];
        }
    }
}

// f(x, y) xor f(y, z) == f(x, z) xor y
// lets consider each bit
// if the most sig 1 in y, corresponds to a 0 in f(x, z)
// then we are good, otherwise we are not

// for each y, consider the leading bit
// how many x, z such that f(x, z) has a 1 in that bit
