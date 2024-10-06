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

const int MOD = 998244353;

void solve() {
    string s;
    int k;
    cin >> s >> k;
    int n = sz(s);

    vector<int> change;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            if (i == n - 1 || s[i + 1] == '?') {
                change.push_back(i);
                continue;
            }

            int ndig = s[i + 1] - '0';
            if (ndig <= 6) {
                change.push_back(i);
            }
        }
    }

    if (n == 1 && s[0] == '?') {
        s[0] = (char)('0' + 10 - k);
    }
    else {
        k--;
        if (s[n - 1] == '?' && s[n - 2] == '?') {
            // any combination 1(1-9) or 2(1-6) would work
            int local = k % 15;
            // 26 25 24 23 22 21, 19 18 17 16 15 14 13 12 11

            if (local <= 5) {
                s[n - 2] = '2';
                s[n - 1] = '6' - local;
            }
            else {
                s[n - 2] = '1';
                s[n - 1] = '9' + 6 - local;
            }

            change.pop_back();
            change.pop_back();
            k /= 15;
        }
        // if ending is 2? -> 2(1-6)
        else if (s[n - 1] == '?' && s[n - 2] == '2') {
            int local = k % 6;
            s[n - 1] = '6' - local;
            change.pop_back();
            k /= 6;
        }
        // if ending is a? -> 1(1 - 9)
        else if (s[n - 1] == '?') {
            // all combs a(1-9)
            int local = k % 9;
            s[n - 1] = '9' - local;
            change.pop_back();
            k /= 9;
        }

        // 226, 5, 4, 3, 2, 1 -> 126, 5, 4, 3, 2, 1

        for (int i = sz(change) - 1; i >= 0; i--) {
            if (k % 2) {
                s[change[i]] = '1';
            }
            else {
                s[change[i]] = '2';
            }

            k /= 2;
        }

        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                s[i] = '1';
            }
        }
    }

    // now that we found s, count # of ways we can interpret

    vector<int> dp(n + 1);
    dp[n] = 1;
    dp[n - 1] = (s[n - 1] != '0');
    for (int i = n - 2; i >= 0; i--) {
        // if single digit
        if (s[i + 1] != '0') {
            dp[i] += dp[i + 1];
            dp[i] %= MOD;
        }

        // if double digit
        if ((s[i] == '2' && s[i + 1] - '0' <= 6) || s[i] == '1') {
            dp[i] += dp[i + 2];
            dp[i] %= MOD;
        }
    }

    int ans = dp[0] % MOD;
    cout << s << ' ' << ans << '\n';
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}

//         10100111001
//         10100111000
// 2222222212122111222
//
// 0 -> 2, 1 -> 1


// 2?? 3 -> 211, 212, 221, 222
// 212 3
// 2 1 2, 2 12, 21 2
// 2 1 3, 2 13, 21 3

// 6??6 2 -> 6116, 6126, 6216, 6226
// 6216 3
// 6 2 1 6, 6 2 16, 6 21 6

// 7??7 1 -> 7117 -> 7217
// 7217 2
// 7 2 1 7, 7 2 17, 7 21 7
