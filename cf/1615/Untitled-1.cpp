#include <bits/stdc++.h>

using namespace std;

int lessN(int n)
{
    int a = 2;
    int k = 0;

    while (a <= n)
    {
        a *= 2;
        k++;
    }

    return k;
}

long long int pt(long long int n)
{
    long long int cnt = -1;
    while (n != 0)
    {
        n /= 2;
        cnt++;
    }
    return cnt;
}

// int retAns(int l, int r)
// {
//     int ansA = 0;
//     int ansB = 0;
//     int ansC = 0;
//     int ansD = 0;
//     int ansE = 0;
//     int ansF = 0;

//     int a = lessN(l);
//     int b = lessN(r);
//     int c = lessN(r) / 2;
//     int d = a / 2;
//     int e = a * 2;
//     int f = b * 2;

//     for (int i = l; i <= r; i++)
//     {
//         if ((i & a) == 0)
//         {
//             ansA++;
//         }

//         if ((i & b) == 0)
//         {
//             ansB++;
//         }

//         if ((i & c) == 0)
//         {
//             ansC++;
//         }

//         if ((i & d) == 0) {
//             ansD++;
//         }

//         if ((i & e) == 0) {
//             ansE++;
//         }

//         if ((i & f) == 0) {
//             ansF++;
//         }
//     }

//     return min(ansA, min(ansB, min(ansC, min(ansD, min(ansE, ansF)))));
// }


int retAns(int l, int r) {
    int ans = INT_MAX;

    for (int i = 1; i <= r; i *= 2)
    {
        int tmp = (r / (i + 1)) - (l / (i + 1));
        ans = min(ans, tmp);
    }
    return ans;
}

int corAns(int l, int r)
{
    int ans = INT_MAX;

    for (int i = 1; i <= r; i *= 2)
    {
        int tmp = 0;
        for (int j = l; j <= r; j++)
        {
            if ((j & i) == 0)
            {
                tmp++;
            }
        }
        // cout << i << " " << tmp << endl;
        ans = min(ans, tmp);
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int l, r;
        cin >> l >> r;

        int ans = INT_MAX;

        for (int i = 1; i <= r; i *= 2)
        {
            int tmp = 0;
            for (int j = l; j <= r; j++)
            {
                if ((j & i) == 0)
                {
                    tmp++;
                }
            }
            cout << i << " " << tmp << endl;
            ans = min(ans, tmp);
        }
        cout << ans << " " << retAns(l, r) << endl;
    }

    // for (int l = 1; l <= 100; l++) {
    //     for (int r = l; r <= 100; r++) {
    //         int c = corAns(l, r);
    //         int t = retAns(l, r);

    //         if (c != t) {
    //             cout << "wa" << l << " " << r << endl;
    //         }
    //     }
    // }
}