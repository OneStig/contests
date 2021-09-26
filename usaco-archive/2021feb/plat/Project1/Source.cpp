#include <vector>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <climits>
#include <set>
#include <algorithm>

using namespace std;

#ifdef LOCAL
ifstream fin("test.in");
ofstream fout("test.out");
#else
#define fin fin
#define fout fout
#endif

vector<int> orig;

void recur(vector<int>& sums) {
    int x = sums[sums.size() - 1] - sums[sums.size() - 2];

    vector<bool> flag(sums.size());

    vector<int> p1, p2;

    bool catchX = 0;

    int j = sums.size() - 2;

    int sdf = 0;

    for (int i : sums) {
        if (i == x) {
            sdf = 1;
            break;
        }
    }

    for (int i = sums.size() - 1; i > 0; i--) {

        if (!flag[i]) {

            p1.push_back(sums[i]);

            j = min(i - 1, j);

            while (j >= 0 && sums[i] - x != sums[j]) {
                j--;
            }

            flag[j] = 1;

            p2.push_back(sums[j]);

        }
    }

    if (sdf) {
        sums = p2;
    }
    else {
        x *= -1;
        sums = p1;
    }

    reverse(sums.begin(), sums.end());

    orig.push_back(x);
}

vector<int> recoverArray(int n, vector<int>& sums) {
    sort(sums.begin(), sums.end());

    for (int i = 0; i < n; i++) {
        recur(sums);
    }

    return orig;
}


int main()
{
    vector<int> in = { 0, -3 };
    vector<int> out = recoverArray(1, in);
}