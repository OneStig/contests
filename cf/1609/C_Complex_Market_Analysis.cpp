#include <bits/stdc++.h>

using namespace std;

int nums[200000];

int isPrime(int k) {
    int n = nums[k];
    if (n == 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, e;
        cin >> n >> e;

        vector<bool> prime(n);

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            prime[i] = isPrime(i);
        }

        vector<long long> pos(n);

        long long sum = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (prime[i] || nums[i] == 1) {
                if (nums[i] == 1) {
                    pos[i] = 1;
                    if (i + e < n) {
                        pos[i] += pos[i + e];
                    }

                    if (pos[i] * e + i < n && prime[pos[i] * e + i]) {
                        sum++;

                        if ((pos[i] + 1) * e + i < n && nums[(pos[i] + 1) * e + i] == 1) {
                            sum += pos[(pos[i] + 1) * e + i];
                        }
                    }
                }
                else {
                    if (i + e < n) {
                        sum += pos[i + e];
                    }
                }
            }
        }

        cout << sum << endl;
    }
}