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
        for (int& x : a) cin >> x;

        vector<int> b(n);
        for (int i = 1; i < n; i += 2) {
            if (i == n - 2) {
                int x, y, z;
                if (a[i] > 0 == a[i - 1] > 0) {
                    x = i - 1, y = i, z = i + 1;
                }
                else if (a[i] > 0 == a[i + 1] > 0) {
                    x = i, y = i + 1, z = i - 1;
                }
                else {
                    x = i - 1, y = i + 1, z = i;
                }

                b[x] = b[y] = a[z];
                b[z] = a[x] + a[y];
                b[z] *= -1;
            }
            else {
                b[i - 1] = a[i];
                b[i] = a[i - 1];
                b[i] *= -1;
            }
        }

        for (int& x : b) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}
