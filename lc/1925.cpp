class Solution {
public:
    int countTriples(int n) {
        vector<bool> allnums(n * n + 1);
        
        for (int i = 1; i <= n; i++) {
            allnums[i * i] = 1;
        }
        
        int total = 0;
        
        for (int a = 1; a <= n; a++) {
            for (int b = a; a * a + b * b <= n * n; b++) {
                if (allnums[a * a + b * b]) {
                    total++;
                }
            }
        }
        
        return total * 2;
    }
};