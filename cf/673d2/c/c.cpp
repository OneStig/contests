#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
#include <cstring>

using namespace std;
 
int main()
{
    ifstream cin("test.in");
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> nums;
        vector<int> orig;

        for (int i = 0; i < n; i++) {
            int in;
            cin >> in;
            orig.push_back(in);
            nums.push_back(in);
        }

        sort(nums.begin(), nums.end());

        int sol[300001];

        memset(sol, -1, sizeof(int) * (n + 1));

        for (int k = n; k != 0; k--) {
            int minm = INT_MAX;
            for (int j = 0; j < n; j += k) {
                
                for (int l = j; l < min(n, j + k); l++) {

                }
            }
        }

        cout << sol[1];

        for (int p = 2; p <= n; p++) {
            cout << " " << sol[p];
        }

        cout << endl;
    }

}