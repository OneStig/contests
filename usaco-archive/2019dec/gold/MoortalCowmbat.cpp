#include <bits/stdc++.h>

using namespace std;

int n, m, k;
string s;

int preseg[100005][27];
int segtree[100005][27];
int dp[100005][27];
int input[27][27];

int segment(int l, int r, int c)
{
    int ret = 0;
    for (int i = 0; i < m; i++)
    {
        int num = preseg[r][i];
        if (l != 0) {
            num -= preseg[l - 1][i];
        }
            
        ret += input[i][c] * num;
    }
    return ret;
}

int searching(int x, int c)
{
    if (x == n)
    {
        return 0;
    }
    int &ret = dp[x][c];
    if (ret != -1)
        return ret;
    int cur = s[x] - 'a';
    ret = searching(x + 1, c) + input[cur][c];
    if ((x + k) <= n)
    {
        for (int i = 0; i < m; i++)
        {
            ret = min(ret, searching(x + k, i) + segtree[x][i]);
        }
    }
    return ret;
}
int main()
{
    cin >> n >> m >> k >> s;

    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> input[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int z = 0; z < m; z++)
        {
            for (int j = 0; j < m; j++)
            {
                input[z][j] = min(input[z][j], input[z][i] + input[i][j]);
            }
        }
    }

    preseg[0][s[0] - 'a'] = 1;

    for (int i = 1; i < n; i++)
    {
        preseg[i][s[i] - 'a'] = 1;
        for (int j = 0; j < m; j++)
        {
            preseg[i][j] += preseg[i - 1][j];
        }
    }
    for (int i = 0; i <= n - k; i++)
    {
        for (int j = 0; j < m; j++)
        {
            segtree[i][j] = segment(i, i + k - 1, j);
        }
    }

    int sol = INT_MAX;

    for (int i = 0; i < m; i++)
    {
        sol = min(sol, searching(k, i) + segtree[0][i]);
    }

    cout << sol;
}
