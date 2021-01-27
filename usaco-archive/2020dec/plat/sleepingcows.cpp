#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, bool>> events;

    int type = 0;

    for (int i = 0; i < 2 * n; i++)
    {
        if (i >= n)
        {
            type = 1;
        }
        int tmp;
        cin >> tmp;

        events.push_back({tmp, type});
    }

    sort(events.begin(), events.end());

    int MOD = 1000000007;

    int dp[n + 1][2];
    int ndp[n + 1][2];

    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;

    for (pair<int, bool> e : events)
    {
        memset(ndp, 0, sizeof(ndp));

        if (e.second)
        {
            for (int a = 0; a < n; a++)
            {
                if (a > 0)
                {
                    for (int j = 0; j < 2; j++)
                    {
                        ndp[a - 1][j] = (ndp[a - 1][j] + (a * (long long)dp[a][j])) % MOD;
                    }
                }
                ndp[a][0] += dp[a][0];
            }
        }
        else
        {
            for (int a = 0; a < n; a++)
            {
                for (int j = 0; j < 2; j++)
                {
                    ndp[a + 1][j] += dp[a][j];
                    ndp[a + 1][j] %= MOD;

                    ndp[a][1] += dp[a][j];
                    ndp[a][1] %= MOD;
                }
            }
        }

        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = ndp[i][0];
            dp[i][1] = ndp[i][1];
        }
    }

    cout << (dp[0][0] + dp[0][1]) % MOD << endl;
}