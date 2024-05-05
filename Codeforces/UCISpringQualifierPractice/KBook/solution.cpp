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
#define ld long double
#define szof(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> pages(n + 1, 1);
        vector<vector<int>> adj(n + 1);
        vector<int> deg(n + 1);

        for (int i = 1; i <= n; i++) {
            int k;
            cin >> k;

            for (int j = 1; j <= k; j++) {
                int x;
                cin >> x;

                adj[x].push_back(i);
                deg[i]++;
            }
        }

        int tot = 0;
        queue<int> q;

        for (int i = 1; i <= n; i++) {
            if (deg[i] == 0) {
                q.push(i);
                tot++;
            }
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int nxt : adj[cur]) {
                if (--deg[nxt] == 0) {
                    tot++;
                    q.push(nxt);
                }

                pages[nxt] = max(pages[nxt], pages[cur] + (cur > nxt));
            }
        }

        if (tot != n) {
            cout << -1 << '\n';
            continue;
        }

        cout << *max_element(all(pages)) << '\n';
    }
}
