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

#define ll long long
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

        vector<int> b(n / 2);
        vector<int> a(n / 2);

        bool valid = 1;
        vector<int> seen(n + 1);

        for (int& x : b) {
            cin >> x;

            if (seen[x]++) {
                valid = 0;
            }
        }

        set<int> unseen;
        for (int i = 1; i <= n; i++) {
            if (!seen[i]) {
                unseen.insert(i);
            }
        }

        for (int i = n / 2 - 1; i >= 0; i--) {
            auto it = unseen.lower_bound(b[i]);

            if (it == unseen.begin()) {
                valid = 0;
                break;
            }

            it--;

            a[i] = *it;
            unseen.erase(it);
        }

        if (!valid) {
            cout << -1 << '\n';
            continue;
        }

        for (int i = 0; i < n / 2; i++) {
            cout << a[i] << ' ' << b[i] << ' ';
        }

        cout << '\n';
    }
}
