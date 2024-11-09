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

const int INF = 1e9;

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
    }

    sort(all(a));
    // dbg(a);

    int ans = INF;
    int l = 0, r = INF;
    while (l < r){
        int mid = (l + r) / 2;
        int last = 0, remain = 0;
        int skip{};

        // dbg(l, r, mid);

        for (auto& cur : a) {
            int dead = cur.second, pages = cur.first;

            if (pages <= remain && dead >= last) {
                remain -= pages;
                continue;
            }

            pages -= remain;
            int going = last + ((pages + mid - 1) / mid);

            // dbg(going);

            if (dead < going) {
                skip++;
            }
            else {
                last = going;
                if (pages % mid == 0) {
                    remain = 0;
                }
                else {
                    remain = mid - (pages % mid);
                }
            }

            // dbg(cur, last, remain, skip);
        }

        if (skip <= m) {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    cout << ans << "\n";
}
