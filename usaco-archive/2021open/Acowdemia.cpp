#include <bits/stdc++.h>

using namespace std;

vector<int> nums;
int n, k, l, sol;

int bans = -1;

void bsearch(int l, int r, int x) {
    if (r < l) {
        return;
    }

    int m = (r - l) / 2 + l;

    if (nums[m] >= x) {
        bans = max(bans, m);
        if (l != r) {
            bsearch(l, m - 1, x);
        }
        return;
    }

    bsearch(m + 1, r, x);
}


bool check(int x) {
    bans = -1;

    bsearch(0, nums.size() - 1, x);
    int count = nums.size() - bans;
    int survey = l;

    if (count >= x) {
        return true;
    }

    vector<int> remain(l + 1, 0);
    remain[l] = k;

    for (int i = bans - 1; i >= 0; i--)
    {
        if (survey > 0)
        {
            int tmp = survey;
            int diff = x - nums[i];
            int perm = 0;

            while (survey > 0 && diff > 0)
            {
                int nperm = min(remain[survey] - perm, diff);
                diff -= nperm;
                remain[survey] -= nperm;
                remain[survey - 1] += nperm;


                if (remain[survey] - perm == 0)
                {
                    perm = nperm;
                    survey--; //switch surveys
                }
                if (remain[survey] == 0) {
                    tmp--;
                }
            }

            if (diff == 0) {
                survey = tmp; // switch back
                count++;
            } 
            else {
                break;
            }
        }
    }

    return count >= x;
}

void search() {
    int l = 0;
    int r = min(nums[nums.size() - 1], n);

    while (l <= r) {
        int m = (r - l) / 2 + l;

        if (check(m) == 1) {
            sol = m;
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
}

int main()
{
    cin >> n >> k >> l;
    sol = -1;
    int t;    

    for (int i = 0; i < n; i++) {
        cin >> t;
        nums.push_back(t);
    }

    sort(nums.begin(), nums.end());
    
    search();

    cout << sol << endl;
}