#include"headFile.h"
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;  // No need to remove duplicates if array size is 2 or less
        }

        int index = 2;  // Start from the third element
        for (int i = 2; i < n; ++i) {
            if (nums[i] != nums[index - 2]) {
                nums[index++] = nums[i];
            }
        }

        return index;
    }
};