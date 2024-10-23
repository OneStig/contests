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

bool get() {
    bool s;
    cin >> s;
    return s;
}

bool ask(string s) {
    cout << "? " << s << endl;
    return get();
}

const int MAX_B = 32;

mt19937 rng(time(nullptr));

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int cur = get();
    for (int i = 1; i < MAX_B; i++) {
        if (cur) {
            ask("flip");
        }
        cur = ask("right");
    }

    if (!cur) {
        ask("flip");
    }

    int ans = -1;
    for (int i = 1; i < MAX_B; i++) {
        cur = ask("left");
        if (cur) {
            ans = i;
            break;
        }
    }

    if (ans != -1) {
        cout << "! " << ans << endl;
        return 0;
    }

    unsigned seq = rng(), sfx{};

    int i = 0;
    while (1) {
        sfx = sfx >> 1;
        sfx += cur << (MAX_B - 1);

        if (sfx == seq) {
            break;
        }

        bool expect = (bool)((1 << (i % MAX_B)) & seq);
        if (cur != expect) {
            ask("flip");
        }

        cur = ask("right");
        i++;
    }

    ans = i - MAX_B + 1;
    cout << "! " << ans << endl;
}
