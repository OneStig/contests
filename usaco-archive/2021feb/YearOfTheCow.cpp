#include <bits/stdc++.h>

using namespace std;

long long n, k;

int main()
{
    cin >> n >> k;

    long long larg = 0;

    vector<long long> nums;
    vector<long long> gaps;
    nums.push_back(0);

    for (int i = 0; i < n; i++)
    {
        long long t;
        cin >> t;

        larg = max(larg, t);
        nums.push_back(t);
    }

    larg = (larg / 12 + 1) * 12;

    sort(nums.rbegin(), nums.rend());

    long long jk = 0;

    for (int i = 0; i < n; i++)
    {
        long long fgap = nums[i] / 12 * 12;
        long long bgap = nums[i + 1] / 12;

        if (nums[i + 1] != 0)
        {
            bgap++;
        }

        bgap *= 12;

        gaps.push_back(fgap - bgap);
        jk++;
    }

    sort(gaps.rbegin(), gaps.rend());

    //k = min(k - 1, jk);
    k--;

    for (int i = 0; i < k; i++)
    {
        larg -= gaps[i];

        if (gaps[i] <= 0)
        {
            break;
        }
    }

    cout << larg << endl;
}
