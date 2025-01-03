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

    int n, m, q;
    cin >> n >> m >> q;
    
    vector<int> a(n), b(m);
    set<int> ina, inb;
    int asum = 0, bsum = 0;
    for (int& x : a) {
        cin >> x;
        ina.insert(x);
        asum += x;
    }

    for (int& x : b)  {
        cin >> x;
        inb.insert(x);
        bsum += x;
    }

    // int beauty = asum + bsum;

    while (q--) {
        int targ;
        cin >> targ;
    
        bool yes = 0;
        int srt = sqrt(abs(targ));
        for (int f = -srt; f <= srt; f++) {
            if (f == 0) continue;
            if (targ % f == 0) {
                int ff = targ / f;
            
                if ((ina.count(asum - f) && inb.count(bsum - ff)) || (ina.count(asum - ff) && inb.count(bsum - f))) {
                    yes = 1;
                    break;
                }
            }
        }

        cout << (yes ? "YES" : "NO") << '\n';
    }
}
