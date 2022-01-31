#include <bits/stdc++.h>

using namespace std;

struct SetUnion
{
    vector<int> all;
    SetUnion(int size)
    {
        all = vector<int>(size, -1);
    }

    int get(int x)
    {
        if (all[x] < 0)
        {
            return x;
        }

        return all[x] = get(all[x]);
    }

    int size(int x)
    {
        return -all[get(x)];
    }

    void unite(int x, int y)
    {
        x = get(x), y = get(y);
        if (x != y)
        {
            if (all[x] > all[y])
                swap(x, y);
            all[x] += all[y];
            all[y] = x;
        }
    }
};

int getDistance(vector<int> a, vector<int> b)
{
    int answer = INT_MAX;

    for (int i : b) {
        if(i < a[0]) {
            answer = min(answer, abs(a[0] - i));
        }
        if(i > a[a.size() - 1]) {
            answer = min(answer, abs(a[a.size() - 1] - i));
        }

        int lo = 0;
        int hi = a.size() - 1;

        while (lo <= hi) {
            int mid = (hi + lo) / 2;

            if (i < a[mid]) {
                hi = mid - 1;
            } else if (i > a[mid]) {
                lo = mid + 1;
            } else {
                return a[mid];
            }
        }

        int sol = (a[lo] - i) < (i - a[hi]) ? a[lo] : a[hi];

        answer = min(answer, abs(sol - i));
    }

    return answer;
}

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {

        int N;
        int M;

        cin >> N;
        cin >> M;

        SetUnion fields(N + 1);

        for (int j = 0; j < M; j++)
        {
            int first;
            int second;
            cin >> first;
            cin >> second;

            fields.unite(first, second);
        }

        int start = fields.get(1);
        int end = fields.get(N);

        if (start == end)
        {
            cout << 0 << endl;
            continue;
        }

        unordered_map<int, int> flag;
        vector<int> uniqueSets;

        vector<vector<int>> actualSets(N);

        for (int j = 1; j <= N; j++)
        {
            int curSet = fields.get(j);

            actualSets[curSet].push_back(j);

            if (!flag[curSet])
            {
                flag[curSet] = true;
                uniqueSets.push_back(curSet);
            }
        }

        int pans = INT_MAX;

        cout << getDistance(actualSets[1], actualSets[N]) << endl;
    }
}