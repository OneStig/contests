class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        unordered_map<char, vector<int>> occur;

        for (int i = 0; i < s.size(); i++) {
            occur[s[i]].push_back(i);
        }
            
        int ans = 0;
        for (auto &p : occur)
        {
            auto v = p.second;
            set<char> us;
            if (v.size() >= 2)
            {
                for (int j = v[0] + 1; j < v.back(); j++)
                    us.insert(s[j]);
                ans += us.size();
            }
        }
        return ans;
    }
};