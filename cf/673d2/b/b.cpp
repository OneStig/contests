#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int nums[100000];

int main()
{
    int t;
    cin >> t;

    while (t--) {
        int n, t;
        cin >> n >> t;

        for (int i = 0; i < n; i++) {
            int in;
            cin >> in;
            nums[i] = in;
        }
        map<int, int> al;

        for (int i = 0; i < n; i++) {
            if (i != 0) {
                cout << " ";
            }

            cout << al[nums[i]];

            al[t - nums[i]] = !al[nums[i]];
        }
        cout << endl;
    }
}