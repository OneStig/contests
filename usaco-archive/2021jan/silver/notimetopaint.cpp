#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q, sol;
    string str;
    cin >> n >> q >> str;

    int fbtemp[100001];
    memset(fbtemp, 0, sizeof(fbtemp));

    bool flag = false;

    for (int i = 0; i < 26; i++)
    {
        flag = false;

        for (int j = 0; j < n; j++)
        {
            if (str[j] - 'A' < i)
            {
                flag = false;
            }
            else if (str[j] - 'A' == i && !flag)
            {
                flag = true;
                fbtemp[j]++;
            }
        }
    }

    flag = false;
    
    reverse(str.begin(), str.end());

    int bftemp[100001];
    memset(bftemp, 0, sizeof(bftemp));

    for (int i = 0; i < 26; i++)
    {
        flag = false;

        for (int j = 0; j < n; j++)
        {
            if (str[j] - 'A' < i)
            {
                flag = false;
            }
            else if (str[j] - 'A' == i && !flag)
            {
                flag = true;
                bftemp[j]++;
            }
        }
    }

    // cout << fbtemp[0] << " " << bftemp[0] << endl;

    int fbfull[100001];
    memset(fbfull, 0, sizeof(fbfull));

    int bffull[100001];
    memset(bffull, 0, sizeof(bffull));

    int rsum = 0;

    for (int i = 0; i < n; i++) {
        rsum += fbtemp[i];
        fbfull[i] = rsum;
    }
    rsum = 0;

    for (int i = 0; i < n; i++) {
        rsum += bftemp[i];
        bffull[i] = rsum;
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        int sol = 0;

        if (a > 1) {
            sol += fbfull[a - 2];
        }

        if (b < n) {
            sol += bffull[n - b - 1];
        }

        cout << sol << endl;
    }
}