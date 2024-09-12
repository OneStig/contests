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

    set<int> has;
    for (int i = 0; i <= 99999; i += 3) {
        has.insert(i);
    }
    has.insert(100000);
    int total = sz(has) + 33333;

    cout << total << endl;

    int x;
    cin >> x;
    while (x != -1) {
        if (x == 100000) {
            cout << total << endl;
        }
        else if (has.find(x) == has.end()) {
            if (x % 3 == 1) {
                has.insert(x + 1);
            }
            else {
                has.insert(x - 1);
            }

            cout << -1 << endl;
        }
        else {
            int idx = (x / 3 * 2) + 1;
            if (x % 3) {
                idx++;
            }

            cout << idx << endl;
        }

        cin >> x;
    }

    for (int i = 0; i <= 99999; i += 3) {
        cout << i << endl;

        if (has.find(i + 1) != has.end()) {
            cout << i + 1 << endl;
        }
        else {
            cout << i + 2 << endl;
        }
    }
}
