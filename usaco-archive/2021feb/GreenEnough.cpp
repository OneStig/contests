#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int N;
bool ok[1000][1000];

ll solve()
{
    ll ans = 0;
    for (int i = 0; i < N; ++i)
    {
        vector<bool> all_ones(N, true);
        for (int j = i; j < N; ++j)
        {
            int run = 0;
            for (int k = 0; k < N; ++k)
            {
                all_ones[k] = all_ones[k] & ok[j][k];
                if (all_ones[k])
                    ans += ++run;
                else
                    run = 0;
            }
        }
    }
    return ans;
}

int main()
{
    cin >> N;
    vector<vector<int>> pasture(N, vector<int>(N));
    for (vector<int> &a : pasture)
        for (int &b : a)
            cin >> b;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            ok[i][j] = pasture[i][j] >= 100;
    ll ans = solve();

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            ok[i][j] = pasture[i][j] > 100;
    ans -= solve();

    cout << ans << "\n";
}