#include <bits/stdc++.h>

using namespace std;

int n;
long long sum;
int grid[501][501];
int test[501];
int t;


int main()
{
    cin >> n;
    sum = n * n * (n + 1) * (n + 1) / 4;

    long long ans = 0;

    memset(test, 0, sizeof(0));

    vector<pair<int, int>> lows;
    vector<pair<int, int>> bad;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> t;
            if (t == 100) {
                grid[i][j] = 1;
                lows.push_back({i, j});
            }
            else if (t < 100) {
                grid[i][j] = 0;
                bad.push_back({i, j});
            }
            else {
                grid[i][j] = 2;
            }
        }
    }

    for (int x1 = 0; x1 < n; x1++) {
        for (int y1 = 0; y1 < n; y1++) {
            for (int x2 = x1; x2 < n; x2++) {
                int bo = 0;
                for (int y2 = 0; y2 < n; y2++) {
                    int f = 0;
                    for (auto i : lows) {
                        if (x1 <= i.first && x2 >= i.first && y1 <= i.second && y2 >= i.second) {
                            f = 1;
                            break;
                        }
                    }

                    if (f == 0) {
                        continue;
                    }

                    for (auto i : bad) {
                        if (x1 <= i.first && x2 >= i.first && y1 <= i.second && y2 >= i.second) {
                            f = 0;
                            break;
                        }
                    }

                    if (f == 0) {
                        bo = 1;
                        break;
                    }

                    ans++;
                }

                if (bo) {
                    break;
                }
            }
        }
    }

    cout << ans << endl;
}