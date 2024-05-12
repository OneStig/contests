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

        vector<int> a;

        if (n == 3) {
            cout << "2 1 3" << '\n';
            continue;
        }

        if (n % 2) {
            a.push_back(0);
        }

        if ((n / 2) % 2 == 0) {
            for (int i = 1; i <= n / 2; i++) {
                a.push_back((i << 1));
                a.push_back((i << 1) + 1);
            }
        }
        else {
            for (int i = 1; i <= n / 2; i++) {
                a.push_back((i << 2) + 1);

                if (i == n / 2) {
                    a.push_back((i << 2) + 3);
                }
                else if (i == n / 2 - 1) {
                    a.push_back((i << 2) + 2);
                }
                else {
                    a.push_back(i << 2);
                }
            }
        }

        for (int& x : a) {
            cout << x << ' ';
        }

        cout << '\n';
    }
}
