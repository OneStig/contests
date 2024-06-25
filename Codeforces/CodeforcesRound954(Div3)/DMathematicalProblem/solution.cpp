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

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int sum{};
        vector<int> freq(10);

        for (int i = 0; i < n; i++) {
            freq[s[i] - '0']++;
            if (s[i] != '1') {
                sum += s[i] - '0';
            }
        }

        if (n == 2) {
            cout << (s[0] - '0') * 10 + (s[1] - '0') << '\n';
            continue;
        }

        if ((n > 3 && freq[0]) || (n == 3 && (s[0] == '0' || s[2] == '0'))) {
            cout << 0 << '\n';
            continue;
        }

        int ans{234897};

        for (int i = 0; i < n - 1; i++) {
            int cur = (s[i] - '0') * 10 + (s[i + 1] - '0');

            int cursum = sum;
            if (s[i] != '1') cursum -= s[i] - '0';
            if (s[i + 1] != '1') cursum -= s[i + 1] - '0';

            if (cur == 1) {
                ans = min(ans, cursum);
            }
            else {
                ans = min(ans, cur + cursum);
            }
        }

        cout << max(1ll, ans) << '\n';
    }
}
