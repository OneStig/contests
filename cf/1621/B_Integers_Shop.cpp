#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int l, r, c;

        vector<int> costs(n);
        vector<int> lefts(n);
        vector<int> rights(n);

        int minL = INT_MAX;
        int minLpos = 0;

        int maxR = INT_MIN;
        int maxRpos = 0;

        int lastSame = 0;

        int curCost = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            cin >> l >> r >> c;

            costs[i] = c;
            lefts[i] = l;
            rights[i] = r;

            int potAns = INT_MAX;

            if (l < minL) {
                minLpos = i;
                minL = l;
            }

            if (r > maxR) {
                maxR = r;
                maxRpos = i;
            }

            if (minLpos == i && maxRpos == i) {
                lastSame = i;
                cout << c << endl;
                continue;
            }

            if (lefts[lastSame] == minL && rights[lastSame] == maxR) {
                potAns = costs[lastSame];
            }

            if (l == minL && c < costs[minLpos]) {
                minLpos = i;
                minL = l;
            }

            if (r == maxR && c < costs[maxRpos]) {
                maxR = r;
                maxRpos = i;
            }
 
            if (c <= potAns && l <= minL && r >= maxR) {
                potAns = c;
                lastSame = i;
            }

            cout << min(potAns, costs[minLpos] + costs[maxRpos]) << endl;
        }
    }
}