#include <bits/stdc++.h>

using namespace std;

bool grid[4000][4000];
int neighbors[4000][4000];
int n;
int ans;

void incr(int x, int y)
{
    neighbors[x + 1001][y + 1001]++;
}

void check(int x, int y)
{
    if (neighbors[x + 1001][y + 1001] == 3 && grid[x + 1001][y + 1001] == 1)
    {
        int cx = INT_MIN;
        int cy = INT_MIN;

        if (grid[x + 1001][y - 1 + 1001] == 0)
        {
            cx = x;
            cy = y - 1;
        }
        else if (grid[x + 1001][y + 1 + 1001] == 0)
        {
            cx = x;
            cy = y + 1;
        }
        else if (grid[x - 1 + 1001][y + 1001] == 0)
        {
            cx = x - 1;
            cy = y;
        }
        else if (grid[x + 1 + 1001][y + 1001] == 0)
        {
            cx = x + 1;
            cy = y;
        }

        if (grid[cx + 1001][cy + 1001] == 0 && cx != INT_MIN && cy != INT_MIN)
        {
            ans++;

            grid[cx + 1001][cy + 1001] = 1;

            incr(cx, cy - 1);
            incr(cx, cy + 1);
            incr(cx - 1, cy);
            incr(cx + 1, cy);

            check(cx, cy - 1);
            check(cx, cy + 1);
            check(cx - 1, cy);
            check(cx + 1, cy);

            check(cx, cy);
        }
    }
}

void addp(int x, int y)
{
    grid[x + 1001][y + 1001] = 1;
    incr(x, y - 1);
    incr(x, y + 1);
    incr(x - 1, y);
    incr(x + 1, y);

    check(x, y - 1);
    check(x, y + 1);
    check(x - 1, y);
    check(x + 1, y);

    check(x, y);
}

int main()
{
    cin >> n;
    ans = 0;
    memset(grid, 0, sizeof(grid));
    memset(neighbors, 0, sizeof(neighbors));

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        if (grid[x + 1001][y + 1001] == 1)
        {
            ans--;
        }
        else
        {
            addp(x, y);
        }

        cout << ans << endl;
    }
}