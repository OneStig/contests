#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, c;
    int nums[1000];
    int dp[2][1000]; // almost 1d dp, expanding dimension like rui's dad explained

    for (int i = 0; i < 1000; i++) {
        dp[0][i] = -1;
        dp[1][i] = -1;
    }

    int ans = 0;
    dp[0][1] = 0;

    vector<pair<int, int>> edges;

    cin >> n >> m >> c;

    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        edges.push_back(make_pair(a, b));
    }

    for (int t = 1; t < 1000; t++)
    {
        int position = t % 2;

        for (int i = 0; i < 1000; i++) {
            dp[position][i] = -1;
        }

        for (pair<int, int> e : edges)
        {
            int a, b;
            a = e.first;
            b = e.second;

            if (0 <= dp[1 - position][a])
            {
                dp[position][b] = max(dp[position][b], dp[1 - position][a] + nums[b]);
            }
        }

        ans = max(ans, dp[position][1] - c * t * t);
    }
    
    cout << ans << endl;
}