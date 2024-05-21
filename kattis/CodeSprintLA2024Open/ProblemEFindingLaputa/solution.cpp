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
typedef int uci;
#define int long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

int n;

vector<int> makeNums(vector<bool> occ) {
    vector<int> nums;
    nums.push_back(0);

    for (int bit = 0; bit < n; bit++) {
        if (occ[n - bit - 1]) {
            for (int& x : nums) {
                x *= 2;
            }
        }
        else {
            vector<int> newnums;

            for (int& x : nums) {
                newnums.push_back(2 * x);
                newnums.push_back(2 * x + 1);
            }

            nums = newnums;
        }
    }

    return nums;
}

unordered_map<int, unordered_map<int, bool>> newEdge;
uci main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    int hce = n * (1 << (n - 1));
    vector<vector<pair<int, int>>> adj(1 << n);


    while (hce--) {
        int i, j, w;
        cin >> i >> j >> w;
        adj[i].push_back({j, w});
        adj[j].push_back({i, w});
    }

    for (int i = 0; i < n; i++) {
        vector<bool> occ(n,0);
        occ[i] = 1;

        for (int j = i + 1; j < n; j++) {
            occ[j] = 1;

            vector<int> nums2 = makeNums(occ);

            for (int& a : nums2) {
                int b = a;
                b |= 1 << i;
                b |= 1 << j;

                adj[a].push_back({b, 4});
                adj[b].push_back({a, 4});
                newEdge[a][b] = 1;
                newEdge[b][a] = 1;
            }

            for (int k = j + 1; k < n; k++) {
                occ[k] = 1;

                vector<int> nums3 = makeNums(occ);

                for (int& a : nums3) {
                    int b = a;
                    b |= 1 << i;
                    b |= 1 << j;
                    b |= 1 << k;

                    adj[a].push_back({b, 9});
                    adj[b].push_back({a, 9});
                    newEdge[a][b] = 1;
                    newEdge[b][a] = 1;
                }

                for (int l = k + 1; l < n; l++) {
                    occ[l] = 1;

                    vector<int> nums4 = makeNums(occ);

                    for (int& a : nums4) {
                        int b = a;
                        b |= 1 << i;
                        b |= 1 << j;
                        b |= 1 << k;
                        b |= 1 << l;

                        adj[a].push_back({b, 16});
                        adj[b].push_back({a, 16});
                        newEdge[a][b] = 1;
                        newEdge[b][a] = 1;
                    }
                    occ[l] = 0;
                }
                occ[k] = 0;
            }
            occ[j] = 0;
        }
        occ[i] = 0;
    }

    dbg(newEdge);

    vector<pair<int, int>> nodes(1 << n, {1e9, 0});
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    pq.push({0, 0, 0});

    while (!pq.empty()) {
        const auto [cdist, cnode, newc] = pq.top();
        pq.pop();

        if (nodes[cnode].first < cdist) continue;

        if (nodes[cnode].first == cdist) {
            nodes[cnode].second = min(nodes[cnode].second, newc);
            continue;
        }

        nodes[cnode].first = cdist;
        nodes[cnode].second = newc;

        for (auto& nb : adj[cnode]) {
            if (nodes[nb.first].first != 1e9) continue;

            pq.push({cdist + nb.second, nb.first, newc + (newEdge[cnode][nb.first])});
        }
    }

    cout << nodes[(1 << n) - 1].first << '\n' << nodes[(1 << n) - 1].second << '\n';
}
