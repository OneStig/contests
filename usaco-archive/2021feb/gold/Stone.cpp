#include <bits/stdc++.h>

using namespace std;

int n, sums[10000], cnt[10000];

int main()
{
    cin >> n;

    long long ans = 0;
    int maxv = 0;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        sums[x]++;
        maxv = max(maxv, x);
    }

    for (int i = 1; i <= maxv; i++) {
        sums[i] += sums[i - 1];
    }
        
    for (int k = 1; k <= maxv; k++)
    {
        int odd = 0, fo = 0;
        
        for (int mul = 1; mul * k <= maxv; mul++)
        {
            cnt[mul] = sums[min(mul * k + k - 1, maxv)] - sums[mul * k - 1];
            if (cnt[mul] % 2 == 1)
            {
                odd++;
                if (odd == 1)
                    fo = mul;
                else if (fo != mul - 1)
                    odd++;
                if (odd >= 3)
                    break;
            }
        }
        if (odd == 2)
            ans += cnt[fo + 1];
        else if (odd == 1 && fo == 1)
            ans += cnt[1];
    }
    
    cout << ans << endl;
}