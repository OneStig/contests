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

        string a, b;
        cin >> a >> b;

        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] == '0' && b[i] == '1')
            {
                sum++;
                b[i] == '0';
            }
            else if (a[i] == '1')
            {
                if (i - 1 >= 0 && b[i - 1] == '1')
                {
                    a[i] = '2';
                    b[i - 1] = '0';
                    sum++;
                }
                else if (i + 1 < n && b[i + 1] == '1')
                {
                    a[i] = '2';
                    b[i + 1] = '0';
                    sum++;
                }
            }
        }

        cout << sum << endl;
    }
}