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

    int n;
    cin >> n;

    vector<int> a(n);
    for (int& x : a) cin >> x;
    sort(all(a));

    int l = 0, r = (n + 1) / 2 - 1;
    while (l < r) {
        int mid = (l + r + 1) / 2;

        bool good = 1;
        for (int i = 0; i < mid; i++) {
            if (a[i] >= a[sz(a) - mid - 1 + i]) {
                good = 0;
                break;
            }
        }

        if (good) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }

    vector<int> ans;
    ans.reserve(n);
    ans.push_back(a[n - l - 1]);

    for (int i = 0; i < l; i++) {
        ans.push_back(a[i]);
        ans.push_back(a[n - l + i]);
    }

    for (int i = l; i < n - l - 1; i++) {
        ans.push_back(a[i]);
    }

    cout << l << '\n';
    for (int& x : ans) cout << x << ' ';
    cout << '\n';
}
