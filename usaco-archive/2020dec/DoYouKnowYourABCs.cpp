#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> nums(7);

    for (int i = 0; i < 7; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end());

    int last;

    for (int i = 2; i < 7; i++)
    {
        if (nums[i] != nums[0] + nums[1])
        {
            cout << nums[0] << " " << nums[1] <<  " " << nums[i] << endl;
            return 0;
        }
    }
}
