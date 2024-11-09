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

int iv = 0;
int f(int a, int b) {return a + b; }

struct ST {
    vector<int> s; int n;
    ST(int n = 0) : s(2 * n, iv), n(n) {}
    void update(int i, int v) {
        for (s[i += n] = v; i /= 2;) {
            s[i] = f(s[i * 2], s[i * 2 + 1]);
        }
    }

    int query(int b, int e) { // [b, e)
        int r = iv;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) r = f(r, s[b++]);
            if (e % 2) r = f(s[--e], r);
        }

        return r;
    }
};

uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> k(n);
    ST st(n);

    for (int i = 0; i < n; i++) {
        cin >> k[i];
        st.update(i, 1);
    }

    int turn{};
    for (int rem = n; rem > 1; rem--) {
        int target = (turn + k[turn] - 1) % rem;
        target += 1;
        // dbg(target);
        int l = 0, r = n - 1;
        while (l < r) {
            int m = (l + r) / 2;
            int q = st.query(l, r + 1);
            //dbg(l, r, m , q, target);
            if (q == target) {
                l = m;
                break;
            }

            if (q < target) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }

        // l is the deletion
        int remo = l;
        int nextturn;

        if (target == rem) {
            nextturn = 1;
        }
        else {
            nextturn = target + 1;
        }

        l = 0, r = n - 1;
        while (l < r) {
            int m = (l + r) / 2;
            int q = st.query(l, r + 1);
            if (q == nextturn) {
                l = m;
                break;
            }

            if (q < nextturn) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }

        turn = l;
        // dbg(remo, turn);
        st.update(remo, 0);
        k[remo] = -1;
    }

    int ans{};
    for (int i = 0; i < n; i++) {
        if (k[i] != -1) {
            ans = i + 1;
            break;
        }
    }

    cout << ans << '\n';
}
