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

const int MAX_R = 2e5;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    vector<int> nums(MAX_R + 1), pfx(MAX_R + 1);

    for (int i = 1; i <= MAX_R; i++) {
        int cur = i;
        while (cur != 0) {
            cur /= 3;
            nums[i]++;
        }

        pfx[i] = nums[i] + pfx[i - 1];
    }

    while (t--) {
        int l, r;
        cin >> l >> r;

        int ans = pfx[r] - pfx[l - 1] + nums[l];
        cout << ans << '\n';
    }
}

// 1, 2, 3 -> 0, 6, 3 -> 0, 2, 3 -> 0, 0, 3 -> 0, 0, 1 -> 0, 0, 0
