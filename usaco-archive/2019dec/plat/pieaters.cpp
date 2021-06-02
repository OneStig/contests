#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(); cin.tie(0);
    freopen("pieaters.in", "r", stdin); freopen("pieaters.out", "w", stdout);

    int N, M;
    int maxweights[300][300][300];
    int dp[300][300];
    cin >> N >> M;

    vector<int> weights(M), l(M), r(M);

    for (int i = 0; i < M; i++) {
        cin >> weights[i] >> l[i] >> r[i];
        l[i]--;
        r[i]--;

        for (int j = l[i]; j <= r[i]; j++) {
            maxweights[j][l[i]][r[i]] = max(maxweights[j][l[i]][r[i]], weights[i]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = i; i >= 0; i--) {
            for (int k = i; k < N; k++) {
                if (j > 0) {
                    maxweights[i][j - 1][k] = max(maxweights[i][j - 1][k], maxweights[i][j][k]);
                }

                if (k <= N) {
                    maxweights[i][j][k + 1] = max(maxweights[i][j][k + 1], maxweights[i][j][k]);
                }
            }
        }
    }

    for (int a = N - 1; a >= 0; a--) {
        for (int b = a; b < N; b++) {
            for (int i = a; i < b; i++) {
                dp[a][b] = max(dp[a][b], dp[a][i] + dp[i + 1][b]);
            }

            for (int i = a; i <= b; i++) {
                int lastcow = 0;

                if (i > a) {
                    lastcow += dp[a][i - 1];
                }

                if (i < b) {
                    lastcow += dp[i + 1][b];
                }

                dp[a][b] = max(dp[a][b], lastcow + maxweights[i][a][b]);
            }
        }
    }

    cout << dp[0][N - 1] << endl;
}