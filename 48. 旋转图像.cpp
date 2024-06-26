#include"headFile.h"
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size() - 1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }
        for (int i = 0; i<n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
        return;
    }
};