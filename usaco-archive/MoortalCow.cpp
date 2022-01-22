#include <bits/stdc++.h>

using namespace std;

int costs[26][26];
int scost[100001][26];
int pscost[100001][26];
int dp[100001][26];
int dpmin[100001];

int main() {
    freopen("cowmbat.in", "r", stdin);
    freopen("cowmbat.out", "w", stdout);

    int n, m, k;
    string s;
    cin >> n >> m >> k >> s;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> costs[i][j];
        }
    }

    for (int k = 0; k < m; k++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]);
            }
        }
    }

    memset(pscost, 0, sizeof(pscost));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            scost[i][j] = costs[s[i - 1] - 'a'][j];
            pscost[i][j] = pscost[i - 1][j] + scost[i][j];
        }
    }

    memset(dp, 0x3f, sizeof(dp));
    memset(dpmin, 0x3f, sizeof(dpmin));

    dpmin[0] = 0;

    for (int i = k; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = min(dp[i - 1][j] + scost[i][j],
            dpmin[i - k] + pscost[i][j] - pscost[i - k][j]);

            dpmin[i] = min(dpmin[i], dp[i][j]);
        }
    }

    cout << dpmin[n] << endl;
}