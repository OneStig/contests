#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> neg;
        vector<int> pos;

        int tmp;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;

            if (tmp < 0)
            {
                neg.push_back(abs(tmp));
            }
            else
            {
                pos.push_back(tmp);
            }
        }

        sort(neg.begin(), neg.end());
        sort(pos.begin(), pos.end());

        long long ans = 0;

        if (neg.size() != 0)
        {
            for (int i = neg.size() - 1; i >= 0;)
            {
                ans += neg[i] * 2;
                i -= k;
            }

            ans -= neg[neg.size() - 1];
        }

        if (pos.size() != 0)
        {
            for (int i = pos.size() - 1; i >= 0;)
            {
                ans += pos[i] * 2;
                i -= k;
            }

            ans -= pos[pos.size() - 1];
        }

        if (pos.size() != 0 && neg.size() != 0) {
            ans += min(pos[pos.size() - 1], neg[neg.size() - 1]);
        }

        cout << ans << endl;
    }
}