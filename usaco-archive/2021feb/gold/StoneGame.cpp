#include <bits/stdc++.h>

using namespace std;

int N;
int larg = INT_MIN;
vector<int> cuml;

int getCumulative(int ind)
{
    if (ind > larg)
    {
        return cuml.back();
    }

    return cuml[ind];
}

int main()
{
    cin >> N;
    vector<int> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> t;
        larg = max(larg, t);
    }

    cuml.resize(larg + 1);

    for (int i : A)
    {
        cuml[i]++;
    }

    for (int i = 1; i <= larg; i++)
    {
        cuml[i] += cuml[i - 1];
    }

    long long ans = 0;

    for (int x = 1; x <= larg; x++)
    {
        vector<int> counts{0};

        for (int t = 1; x * t <= larg; t++) {
            counts.push_back(getCumulative(x * (t + 1) - 1) - getCumulative(x * t - 1));
        }
            
        vector<int> odd;
        for (int t = 1; t < counts.size(); ++t) {
            if (counts[t] & 1) {
                odd.push_back(t);
            }
        }
            
        if (odd == vector<int>{1} || (odd.size() == 2 && odd[0] + 1 == odd[1])) {
            ans += counts[odd.back()];
        }
    }
    cout << ans << endl;
}