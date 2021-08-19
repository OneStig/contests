class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int count[50001];
        
        memset(count, 0, sizeof(count));
        
        vector<int> unique;
        
        for (int n : nums) {
            if (count[n] == 0) {
                unique.push_back(n);
            }
            
            count[n]++;
        }
        
        int sol = 0;
        
        sort(unique.begin(), unique.end());
        reverse(unique.begin(), unique.end());
        
        for (int i = 0; i < unique.size() - 1; i++) {
            sol += (unique.size() - i - 1) * count[unique[i]];
        }
        
        return sol;
    }
};