#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using db = double;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<string>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR0(i, a) FOR(i, 0, a)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define RFOR0(i, a) RFOR(i, 0, a)

// End of template

bool grid[101][101];
int mc;

vi moves[10000];

void move(int x, int y) {
    moves[mc].push_back(x);
    moves[mc].push_back(y);

    grid[x][y] = !grid[x][y];
}

void check(int x, int y) {
    int c = grid[x][y] + grid[x + 1][y] + grid[x][y + 1] + grid[x + 1][y +  1];

    if (c == 0) {
        return;
    }

    if (c == 4) {
        move(x, y);
        move(x + 1, y);
        move(x, y + 1);

        mc++;
    }
    else if (grid[x][y] == grid[x + 1][y + 1] && grid[x + 1][y] == grid[x][y + 1]) {
        int f = 1;
        FOR(i, x, 2) {
            FOR(j, y, 2) {
                if (!grid[i][j]) {
                    move(i, j);
                }
                else if (f) {
                    move(i, j);
                    f = 0;
                }
            }
        }

        mc++;
    } else if (c == 1) {
        move(x, y);
        move(x + 1, y);
        if (grid[x][y] || grid[x + 1][y + 1]) {
            move(x + 1, y + 1);
        }
        else {
            move(x + 1, y + 1);
        }

        mc++;
    } else if (c == 2) {
        int f = 1;
        FOR(i, x, 2) {
            FOR(j, y, 2) {
                if (!grid[i][j]) {
                    move(i, j);
                }
                else if (f) {
                    move(i, j);
                    f = 0;
                }
            }
        }

        mc++;
    } else if (c == 3) {
        FOR (i, x, 2) {
            FOR(j, y, 2) {
                if (grid[i][j]) {
                    move(i, j);
                }
            }
        }

        mc++;
    }

    check(x, y);
}

void solve()
{
    int t;
    cin >> t;

    while (t--) {
        mc = 0;
        int n, m;
        cin >> n >> m;

        FOR0(i, n*m) {
            moves[i].clear();
        }

        FOR0(i, n) {
            string in;
            cin >> in;

            FOR0(j, m) {
                if (in[j] == '1') {
                    grid[i][j] = 1;
                }
                else {
                    grid[i][j] == 0;
                }
            }
        }

        for (int i = 0; i < n - 1; i += 2) {
            for (int j = 0; j < m - 1; j+= 2) {
                check(i, j);
            }
        }

        if (m % 2) {
            for (int i = 0; i < n - 1; i += 2) {
                check(i, m - 2);
            }
        }

        if (n % 2 ) {
            for (int j = 0; j < m - 1; j += 2) {
                check(n - 2, j);
            }
        }

        if (m % 2 && n % 2) {
            check(n - 2, m - 2);
        }

        cout << mc << endl;

        FOR0(i, mc) {
            FOR0(j, 6) {
                if (j != 0) {
                    cout << " ";
                }

                cout << moves[i][j] + 1;
            }

            cout << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(); cin.tie(0); freopen("test.in", "r", stdin);
    solve();
    return 0;
}