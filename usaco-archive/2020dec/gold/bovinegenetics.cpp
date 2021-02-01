#include <bits/stdc++.h>

using namespace std;

int main()
{

    string s;
    cin >> s;

    int MOD = 1000000007;

    char bfor[4] = {'A', 'G', 'C', 'T'};
    map<char, int> brev = {
        {'A', 0},
        {'G', 1},
        {'C', 2},
        {'T', 3}
    };

    int dp[100001][4][4][4];

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < 4; i++)
    {
        if (s[i] == '?') {
            for (int j = 0; j < 4; j++) {
                dp[0][i][j][j] = 1;
            }
        }
        else {
            dp[0][i][brev[s[i]]][brev[s[i]]] = 1;
        }
    }

    for (int i = 1; i < s.length(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (s[i] == '?' || s[i] == bfor[j])
            {
                for (int k = 0; k < 4; k++)
                {
                    for (int l = 0; l < 4; l++)
                    {
                        for (int m = 0; m < 4; m++)
                        {
                            if (m != j)
                            {
                                dp[i][k][l][j] += dp[i - 1][k][l][m];
                            }
                            if (k == m)
                            {
                                dp[i][l][j][j] += dp[i - 1][k][l][m];
                                
                            }

                            dp[i][k][l][j] %= MOD;
                            dp[i][l][j][j] %= MOD;
                        }
                    }
                }
            }
        }
    }

    long long sol = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            sol += dp[s.length() - 1][j][i][j];
            sol %= MOD;
        }
    }

    cout << sol << endl;
}
