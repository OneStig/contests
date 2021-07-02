#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
 
int main()
{

    int t;
    cin >> t;

    int n, k;
    while (t--) {
        cin >> n >> k;
        vector<int> nums;

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            nums.push_back(a);
        }

        sort(nums.begin(), nums.end());

        int sm = nums[0];
        int sum = 0;
        for (int i = 1; i < n; i++) {
            sum += (k - nums[i]) / sm;
        }

        cout << sum << endl;
    }
}