#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    vector<int> primes;
    primes.push_back(2);

    for (int i = 3; i <= 10; i++) {
        int f = 1;

        for (int j = 0; j < primes.size() && primes[j] * primes[j] <= i; j++) {
            if (i % primes[j] == 0) {
                f = 0;
                break;
            }
        }

        if (f) {
            primes.push_back(i);
        }
    }

    while (t--) {
        int n;
        cin >> n;

        string ans = "YES";

        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;

            int s = 0;

            for (int j = 0; j < primes.size() && primes[j] <= i + 1; j++) {
                if (a % primes[j] != 0) {
                    s = 1;
                    break;
                }
            }

            if (!s) {
                ans = "NO";
                break;
            }
        }

        cout << ans << endl;
    }
}