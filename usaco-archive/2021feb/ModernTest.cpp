#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;

    cin >> N;

    vector<int> nums(N);

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int minlast[301];

    for (int i = 0; i < 301; i++) {
        minlast[i] = -1;
    }
    vector<int> frontback();

    frontback.push_back(0);


    for (int i = 1; i <= N; i++) {
        
        for (int j = 0; j < 301; j++)  {
            minlast[j] = min(nums[i - 1], minlast[j]);
        }

        if (!exist[nums[i]]) {
            t++;
            exist[nums[i]] = true;
        }

        frontback.push_back(frontback[i - 1] + t);
    }

    for (int i = 0; i < N; i++) {
        cout << frontback[i] << endl;
    }
}