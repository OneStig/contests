class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        bool first = true;
        
        for (int i = 0; i < mat.size(); i++) {
            if (!first) {
                break;
            }
            
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] != target[mat.size() - j - 1][i]) {
                    first = false;
                    break;
                }
            }
        }
        
        if (first) {
            return true;
        }
        
        first = true;
        
        for (int i = 0; i < mat.size(); i++) {
            if (!first) {
                break;
            }
            
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[mat.size() - j - 1][i] != target[i][j]) {
                    first = false;
                    break;
                }
            }
        }
        
        if (first) {
            return true;
        }
        
        first = true;
        
        for (int i = 0; i < mat.size(); i++) {
            if (!first) {
                break;
            }
            
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] != target[mat.size() - i - 1][mat[i].size() - j - 1]) {
                    first = false;
                    break;
                }
            }
        }
        
        if (first) {
            return true;
        }
        
        first = true;
        
        for (int i = 0; i < mat.size(); i++) {
            if (!first) {
                break;
            }
            
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] != target[i][j]) {
                    first = false;
                    break;
                }
            }
        }
        
        return first;
    }
};