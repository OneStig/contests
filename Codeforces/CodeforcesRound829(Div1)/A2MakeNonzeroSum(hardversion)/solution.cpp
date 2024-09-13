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
        vector<int> a(n);
        int sum{};
        for (int& x : a) {
            cin >> x;
            sum += x;
        }

        if (sum % 2) {
            cout << -1 << '\n';
            continue;
        }

        vector<int> parts = {n};
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] == 0 || sum == 0) {
                parts.push_back(i);
            }
            else if ((sum > 0 && a[i] == 1) || (sum < 0 && a[i] == -1)) {
                if (i != 0) {
                    if (sum < 0) sum += 2;
                    else sum -= 2;

                    parts.push_back(i - 1);
                    i--;
                    continue;
                }
            }
        }

        if (sum == 0) {
            reverse(all(parts));
            cout << sz(parts) - 1 << '\n';
            for (int i = 0; i < sz(parts) - 1; i++) {
                cout << parts[i] + 1 << ' ' << parts[i + 1] << '\n';
            }
        }
        else {
            cout << -1 << '\n';
        }
    }
}
