
#define problemname "buylow"
#include <bits/stdc++.h>

using namespace std;

int nums[5001];
int subseq[5001] = {1};
int lg[5001];

int main()
{
    ios_base::sync_with_stdio(); cin.tie(0);
    freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);
    int n;
    cin >> n;

    for (int i = n; i; i--)
        cin >> nums[i];
    for (int i = 1; i <= n; i++)
    {
        int len = 0;
        for (int j = 1; j < i; j++)
        {
            if (nums[i] > nums[j])
                len = max(len, lg[j]);
        }
        lg[i] = len + 1;
        for (int j = 0; j < i; j++)
        {
            if (lg[j] == len && nums[j] < nums[i])
                subseq[i] += subseq[j];
        }
        for (int j = 0; j < i; j++)
            if (nums[i] == nums[j] && lg[j] == lg[i])
                subseq[i] -= subseq[j];
    }

    int sol = 0;
    int count = 0;

    for (int i = 1; i <= n; i++)
        sol = max(sol, lg[i]);
    for (int i = 1; i <= n; i++)
        if (lg[i] == sol)
            count += subseq[i];
    
    cout << sol << " " << count;
}
