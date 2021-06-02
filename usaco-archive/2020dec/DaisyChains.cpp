#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, p[100], aug[100];
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> p[i];

    aug[0] = p[0];

    for (int i = 1; i < n; i++) {
        aug[i] = p[i] + aug[i - 1];
    }

    int sol = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            double avg = aug[j];

            if (i != 0) {
                avg -= aug[i - 1];
            }

            avg /= j + 1 - i;

            for (int k = i; k <= j; k++) {
                if (p[k] == avg) {
                    sol++;
                    break;
                }
            }
        }
    }

    cout << sol << endl;
}