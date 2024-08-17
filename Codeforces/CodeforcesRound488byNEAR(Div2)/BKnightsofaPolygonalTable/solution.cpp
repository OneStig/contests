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

    int n, k;
    cin >> n >> k;

    vector<int> coins(n);
    vector<pair<int, int> > kpow(n);

    for (int i = 0; i < n; i++) {
        cin >> kpow[i].first;
        kpow[i].second = i;
    }

    for (int& c : coins) cin >> c;

    sort(all(kpow));

    vector<int> ans(n);
    priority_queue<int> ks;
    int ksum = 0;
    for (int i = 0; i < n; i++) {
        int cur = coins[kpow[i].second];
        ans[kpow[i].second] = cur + ksum;

        ksum += cur;
        ks.push(-cur);
        if (sz(ks) > k) {
            ksum += ks.top();
            ks.pop();
        }
    }

    for (int& x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}
