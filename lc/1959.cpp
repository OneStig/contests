class Solution {
public:
    int dp[200][200][200];
    int altdp[200][200];
    
    int actual[200];
    
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        vector<int> tmp = nums;
        
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        
        int total = 0;
        for (int n : tmp) {
            actual[total++] = n;
        }
        
        for (int i = 0; i < 200; i++) {
            for (int j = 0; j < 200; j++) {
                altdp[i][j] = INT_MAX;
            }
        }
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j <= k; j++) {
                for (int l = 0; l < total; l++) {
                    if (actual[l] < nums[i]) {
                        dp[i][j][l] = INT_MAX / 2;
                        continue;
                    }
                    
                    if (i == 0) {
                        dp[i][j][l] = actual[l] - nums[i];
                    } else if (j == 0) {
                        dp[i][j][l] = dp[i - 1][0][l] + actual[l] - nums[i];
                    } else {
                        dp[i][j][l] = min(dp[i - 1][j][l] + actual[l] - nums[i], altdp[i - 1][j - 1] + actual[l] - nums[i]);
                    }
                    
                    altdp[i][j] = min(altdp[i][j], dp[i][j][l]);
                }
            }
        }
        
        return altdp[nums.size() - 1][k];
    }
};