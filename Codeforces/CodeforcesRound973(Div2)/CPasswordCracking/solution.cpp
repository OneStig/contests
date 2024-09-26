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

bool ask(string t) {
    cout << "? " << t << endl;
    bool resp;
    cin >> resp;
    return resp;
}

void ans(string s) {
    cout << "! " << s << endl;
}

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        bool z = ask("0");
        if (!z) {
            string a = "";
            for (int i = 0; i < n; i++) a += "1";
            ans(a);
            continue;
        }

        string build = "0";

        while (sz(build) < n) {
            bool first = ask(build + "0");
            if (first) {
                build += "0";
                continue;
            }

            bool second = ask(build + "1");
            if (second) {
                build += "1";
                continue;
            }

            break;
        }

        while (sz(build) < n) {
            if (ask("0" + build)) {
                build = "0" + build;
            }
            else {
                build = "1" + build;
            }
        }

        ans(build);
    }
}
