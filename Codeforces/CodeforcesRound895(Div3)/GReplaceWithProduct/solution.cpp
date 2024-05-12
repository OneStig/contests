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

        int MAX_SUM = n * 1e9;

        vector<int> a(n);
        vector<int> indices;
        vector<int> pfx(n);
        vector<int> sum(n);

        int mul = 1;
        int add = 0;
        bool outer = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            add += a[i];
            sum[i] = add;

            if (a[i] != 1) {
                indices.push_back(i);
            }

            if (!outer) {
                if (mul > MAX_SUM / a[i]) {
                    outer = 1;
                }
                else {
                    mul *= a[i];
                    pfx[i] = mul;
                }
            }
        }

        int l{}, r{};
        if (outer) {
            l = indices.front();
            r = indices.back();
        }
        else {
            int mx = sum[n - 1];

            for (int i = 0; i < sz(indices); i++) {
                for (int j = i + 1; j < sz(indices); j++) {
                    int cur = sum[n - 1] - (sum[indices[j]] - (indices[i] ? sum[indices[i] - 1] : 0))
                            + pfx[indices[j]] / (indices[i] ? pfx[indices[i] - 1] : 1);
                    if (cur > mx) {
                        mx = cur;
                        l = indices[i];
                        r = indices[j];
                    }
                }
            }
        }

        cout << l + 1 << ' ' << r + 1 << '\n';
    }
}
