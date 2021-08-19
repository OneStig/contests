class Solution {
public:
    bool sumGame(string num) {
        int q = 0;
        int left = 0;
        int right = 0;
        
        for (int i = 0; i < num.length(); i++) {
            if (num[i] == '?') {
                q++;
            }
            
            if (i < num.length() / 2) {
                if (num[i] == '?') {
                    left += 9;
                }
                else {
                    left += (num[i] - '0') * 2;
                }
            }
            else {
                if (num[i] == '?') {
                    right += 9;
                }
                else {
                    right += (num[i] - '0') * 2;
                }
            }
        }
        
        return q % 2 == 1 || left != right;
    }
};