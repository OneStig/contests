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

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), freq(10);
        for (int& x : a) {
            cin >> x;
            freq[x]++;
        }

        int mimic = -1;
        while (mimic == - 1) {
            cout << "- 0" << endl;
            vector<int> newfreq(10);
            for (int& x : a) {
                cin >> x;
                newfreq[x]++;
            }

            for (int i = 1; i <= 9; i++) {
                if (newfreq[i] > freq[i]) {
                    mimic = i;
                    break;
                }
            }
        }

        vector<int> erase;
        for (int i = 0; i < n; i++) {
            if (a[i] != mimic) {
                erase.push_back(i + 1);
            }
        }

        cout << "- " << sz(erase);
        for (int& x : erase) cout << ' ' << x;
        cout << endl;

        // phase 2 (4, 5)
        vector<int> b(n - sz(erase));
        int ans = -1;
        while (ans == -1) {
            for (int i = 0; i < sz(b); i++) {
                cin >> b[i];
                if (b[i] != mimic) {
                    ans = i + 1;
                }
            }

            if (ans == -1) {
                cout << "- 0" << endl;
            }
        }

        cout << "! " << ans << endl;
    }
}

// 1 (input) -> do nothing
// 2 (input) -> do nothing if no change
// 3 (input) -> mimic changes i.e 1->2, then eliminate all non 2
// 4 (input) -> do nothing if no change
// 5 (input) -> mimic changes away, revealing position
