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

    set<int> good;

    for (int k = 2; k <= 1e6; k++) {
        int sum = 1 + k;
        int mul = k * k;
        for (int p = 3; p <= 63; p++) {
            sum += mul;
            if (sum > 1e18) break;
            good.insert(sum);
            
            if (mul > 1e18 / k) break;
            mul *= k;
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        if (good.ccontains(n)) {
            cout << "YES" << '\n';
        }
        else {

        }
    }
}

// k > 1
// k == 2 : 3,2 -> 7,4 -> 15,8 -> 31,16 -> 63,32
// k == 3 : 4,3 -> 13,9 -> 40,27 -> 121,81
// k == 4 : 5,4 -> 21,16 -> 85,64
// 1 + k + k^2 + k^3 ...
//
// k(k(k(k + 1) + 1) + 1) + 1
