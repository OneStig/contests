class Solution
{
public:
    int addRungs(vector<int> &rungs, int dist)
    {
        int count = 0;
        int prev = 0;

        for (int i = 0; i < rungs.size(); i++)
        {
            if (rungs[i] - prev <= dist)
                ;
            else
            {
                count += (rungs[i] - prev) / dist;
                if ((rungs[i] - prev) % dist == 0) {
                    count--;
                }
                    
            }
            prev = rungs[i];
        }
        return count;
    }
};