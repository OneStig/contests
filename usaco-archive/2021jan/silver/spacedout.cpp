#include <bits/stdc++.h>

using namespace std;

char field[1000][1000];
int beauty[1000][1000], sol;

void dfs(int n, int i, int j)
{
    if (j == n)
    {
        i++;
        j = 0;
    }

    if (i == n)
    {
        int val = 1;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                int br = 0;
                for (int k = 0; k < 2; k++)
                {
                    for (int l = 0; l < 2; l++)
                    {
                        if (field[i + k][j + l] == '-')
                        {
                            br++;
                        }
                    }
                }

                if (br != 2)
                {
                    return;
                }
            }
        }

        int nsol = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (field[i][j] == '-')
                {
                    nsol += beauty[i][j];
                }
            }
        }

        sol = max(nsol, sol);

        return;
    }

    field[i][j] = '=';
    dfs(n, i, j + 1);

    field[i][j] = '-';
    dfs(n, i, j + 1);
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            field[i][j] = '=';
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> beauty[i][j];
        }
    }

    dfs(n, 0, 0);

    cout << sol;
}