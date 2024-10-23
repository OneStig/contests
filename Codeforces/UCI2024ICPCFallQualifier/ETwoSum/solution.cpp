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

#define ull unsigned long long

const int MAX_B = 64;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, a;
    cin >> n >> a;

    int tmp = a;
    int tot{};
    vector<int> b(MAX_B);
    for (int i = 0; tmp != 0; i++) {
        b[i] = tmp % 2;
        tot += b[i];
        tmp /= 2;
    }

    if (n < tot || n > a) {
        cout << "-1\n";
        return 0;
    }

    // otherwise possible, just cascade bits down

    n -= tot;
    for (int i = MAX_B - 1; i >= 0; i--) {
        ull cur = (ull)1 << i;

        if (n >= b[i]) {
            n -= b[i];
            b[i - 1] += 2 * b[i];
            continue;
        }
        else {
            b[i] -= n;
            b[i - 1] += 2 * n;
            n = 0;
        }

        for (int j = 0; j < b[i]; j++) {
            cout << cur << ' ';
        }
    }
    cout << '\n';
}
