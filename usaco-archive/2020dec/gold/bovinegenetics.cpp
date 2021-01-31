#include <bits/stdc++.h>

using namespace std;

int main()
{

    string s;
    cin >> s;

    int MOD = 1000000007;

    int dp[100001][4][4][4];
    char BASES[4] = {'A', 'G', 'C', 'T'};

    for (int n = 0; n < 4; n++)
    {
        for (int l = 0; l < 4; l++)
        {
            if (s[0] == '?' || s[0] == BASES[l])
            {
                dp[0][n][l][l] = 1;
            }
        }
    }

    for (int k = 1; k < s.length(); k++)
    {
        for (int m2 = 0; m2 < 4; m2++)
        {
            if (s[k] == '?' || s[k] == BASES[m2])
            {
                for (int n = 0; n < 4; n++)
                {
                    for (int l = 0; l < 4; l++)
                    {
                        for (int m = 0; m < 4; m++)
                        {
                            if (m != m2)
                            {
                                dp[k][n][l][m2] += dp[k - 1][n][l][m];
                                dp[k][n][l][m2] %= MOD;
                            }
                            if (n == m)
                            {
                                dp[k][l][m2][m2] += dp[k - 1][n][l][m];
                                dp[k][l][m2][m2] %= MOD;
                            }
                        }
                    }
                }
            }
        }
    }

    long answer = 0;
    for (int l = 0; l < 4; l++)
    {
        for (int m = 0; m < 4; m++)
        {
            answer += dp[s.length() - 1][m][l][m];
            answer %= MOD;
        }
    }
    answer %= MOD;

    cout << answer << endl;
}
