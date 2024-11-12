#include <bits/stdc++.h>

using namespace std;

typedef int uci;
#define int long long
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int INF = 1e9;

int iv = 0;
int f(int a, int b) { return a + b; }

struct ST {
    vector<int> s; int n;
    ST(int n = 0) : s(2*n, iv), n(n) {}
    void update(int i, int v) {
        for (s[i += n] = v; i /= 2;)
            s[i] = f(s[i * 2], s[i * 2 + 1]);
    }

    int query(int b, int e) {
        int r = iv;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) r = f(r, s[b++]);
            if (e % 2) r = f(s[--e], r);
        }
        return r;
    }
};

uci main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    vector<int> cust(n + 1, -1); // time they got on
    vector<int> last(2 * n + 1, INF);
    ST cur(2 * n);
    vector<int> cv(2 * n); // actual times

    int ans{};
    for (int i = 0; i < 2 * n; i++) {
        int c, l;
        cin >> c >> l;



        if (last[l] != INF) {
            ans += cur.query(0, last[l] + 1);
        }

        // customer stuff
        if (cust[c] == -1) {
            // getting on
            cust[c] = i;
            cur.update(i, ++cv[i]);
        }
        else {
            // getting off
            cur.update(cust[c], --cv[cust[c]]);
        }

        last[l] = i;
    }

    cout << ans << '\n';
}