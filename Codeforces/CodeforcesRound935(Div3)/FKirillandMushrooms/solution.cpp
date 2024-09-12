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

#define pi pair<int, int>

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pi> a(n); // {v_i, lifetime}
        vector<int> life(n);
        for (auto& x : a) cin >> x.first;
        for (int i = 0; i < n; i++) {
            cin >> life[i];
            a[life[i] - 1].second = i + 1;
            life[i] = -a[life[i] - 1].first;
        }

        sort(all(a), greater<pi>());

        int best{}, take{};
        multiset<int> has;
        int k = 1;
        for (int i = 0; i < n; i++) {
            if (a[i].second >= k) {
                has.insert(a[i].first);
                life[a[i].second - 1] *= -1;
            }

            if (k != 1 && life[k - 2] > 0) {
                // try to remove the k - 1 thing
                has.erase(has.find(life[k - 2]));
                life[k - 2] = -1;
            }

            if (sz(has) == k) {
                int possible = *has.begin() * k;
                if (possible > best) {
                    best = possible;
                    take = k;
                }
                k++;
            }
        }

        cout << best << ' ' << take << '\n';
    }
}
