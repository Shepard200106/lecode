#include"headFile.h"
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0;
        for (int i = 0; i < n; i++) {
            if (matrix[i][m - 1] > target) {
                row = i;
                break;
            }
            if (target == matrix[i][m - 1]) {
                return true;
            }
        }
        int l = 0;
        int h = m - 1;
        while (l < h) {
            int  mid = (l + h) / 2;
            if (target < matrix[row][mid]) {
                h = mid;
            }
            else if(target>matrix[row][mid]) {
                l = mid+1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};