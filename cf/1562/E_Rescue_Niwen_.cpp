
#include <bits/stdc++.h>

using namespace std;

void fun(string s)
{
}

void run()
{
}

int main()
{
    int t;
    cin >> t;

    int n, q;

    int dp[30005];
    int zed[30005];

    while (t--)
    {
        cin >> n;

        string str;
        cin >> str;

        for (int i = 0; i < n; i++) {
            dp[i] = n - i;
        }

        for (int i = 0; i < n; i++)
        {
            int tmp = (int)str.length();
            for (int i = 1, l = 0, r = 0; i < tmp; i++)
            {
                zed[i] = 0;
                if (i <= r)
                {
                    zed[i] = min(r - i + 1, zed[i - l]);
                }

                while (i + zed[i] < tmp && str[zed[i]] == str[i + zed[i]])
                {
                    zed[i]++;
                }

                if (i + zed[i] - 1 > r)
                {
                    l = i;
                    r = i + zed[i] - 1;
                }
            }

            for (int j = 1; j + i < n; j++)
            {
                int k = i + j;

                if (zed[j] + k < n && str[k + zed[j]] > str[i + zed[j]])
                {
                    dp[k] = max(dp[k], dp[i] + (n - k) - zed[j]);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, dp[i]);
        }

        cout << ans << "\n";
    }
}