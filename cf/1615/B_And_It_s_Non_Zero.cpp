#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> sums;

int main()
{
    int t;
    cin >> t;

    sums.resize(200001);

    for (int i = 1; i < 200000; i++) {
        int c = i;
        sums[i] = vector<int>(18);
        sums[i][0] = i % 2;

        for (int j = 1; j <= 18; j++) {
            int bit = 2 ^ j;
            sums[i][j] = sums[i][j - 1] + (i & bit >= 1);
        }
    }

    while (t--)
    {
        int l, r;
        cin >> l >> r;

        int ans = INT_MAX;

        for (int i = 0; i <= 18; i++) {
            int tmp = (r - l + 1) - (sums[r][i] - sums[l][i]);
            ans = min(ans, tmp);
        }
        
        cout << ans << endl;
    }
}