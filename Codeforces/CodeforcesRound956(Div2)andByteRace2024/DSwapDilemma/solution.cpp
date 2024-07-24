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

    vector<int> apos(200001), bpos(200001);

    while (t--) {
        int n;
        cin >> n;
        set<int> freq;
        vector<int> a(n), b(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            apos[a[i]] = i;
            freq.insert(a[i]);
        }

        bool yes = 1;

        for (int i = 0; i < n; i++) {
            cin >> b[i];
            bpos[b[i]] = i;
            if (freq.find(b[i]) == freq.end()) {
                yes = 0;
            }
        }

        if (yes) {
            int swaps{};

            for (int i = 0; i < n; i++) {
                if (a[i] != b[i]) {
                    apos[a[i]] = apos[b[i]];
                    swap(a[i], a[apos[b[i]]]);
                    swaps++;
                }
            }

            yes = !(swaps % 2);
        }

        cout << (yes ? "YES\n" : "NO\n");
    }
}
