#include <bits/stdc++.h>
#include <ratio>

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

int ask(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    int resp;
    cin >> resp;
    return resp;
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> cands(1 << n);
        iota(all(cands), 1);

        while (sz(cands) > 2) {
            vector<int> newc;

            for (int i = 0; i < sz(cands) / 4; i++) {
                int a = cands[i * 4], b = cands[i * 4 + 1], c = cands[i * 4 + 2], d = cands[i * 4 + 3];

                int cur = ask(a, c);
                if (cur == 0) {
                    if (ask(b, d) == 1) newc.push_back(b);
                    else newc.push_back(d);
                }
                else if (cur == 1) {
                    if (ask(a, d) == 1) newc.push_back(a);
                    else newc.push_back(d);
                }
                else {
                    if (ask(b, c) == 1) newc.push_back(b);
                    else newc.push_back(c);
                }
            }

            cands = newc;
        }

        int final;
        if (sz(cands) == 1) {
            final = cands[0];
        }
        else {
            if (ask(cands[0], cands[1]) == 1) final = cands[0];
            else final = cands[1];
        }

        cout << "! " << final << endl;
    }
}
