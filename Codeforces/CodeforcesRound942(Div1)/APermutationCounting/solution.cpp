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
#define ld long double
#define szof(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        ll n, k;
        cin >> n >> k;

        vector<ll> a(n);

        for (ll& x : a) {
            cin >> x;
        }

        sort(a.rbegin(), a.rend());

        ll sm = a[n - 1];
        a.pop_back();

        // count all things that repeat the least
        ll ans = 1;

        while (a.size() && sm == a[a.size() - 1]) {
            ans++;
            a.pop_back();
        }

        while (a.size()) {
            ll diff = a[a.size() - 1] - sm;
            if (k < diff * ans) {
                break;
            }

            k -= diff * ans;
            sm = a[a.size() - 1];

            while (a.size() && sm == a[a.size() - 1]) {
                ans++;
                a.pop_back();
            }
        }

        sm += k / ans;
        ans = ans - (k % ans);
        cout << sm * n - ans + 1 << '\n';
    }
}
