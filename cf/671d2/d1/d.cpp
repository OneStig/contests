#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    int n;
    vector<int> nums;
    vector<int> od;
    cin >> n;

    if (n % 2 == 0) {
        cout << (n / 2) - 1 << endl;
    }
    else {
        cout << n / 2 << endl;
    }

    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        nums.push_back(in);
        od.push_back(in);
    }

    sort(nums.begin(), nums.end());
    sort(od.begin(), od.end());
    reverse(od.begin(), od.end());
    
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            cout << " ";
        }

        if (i % 2 == 0) {
            cout << nums.back();
            nums.pop_back();
        }
        else {
            cout << od.back();
            od.pop_back();
        }
    }

    cout << endl;
}
