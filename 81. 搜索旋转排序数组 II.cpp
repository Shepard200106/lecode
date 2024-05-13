#include <vector>

class Solution {
public:
    bool search(std::vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return true;
            }

            if (nums[left] < nums[mid]) {  // 左半部分有序
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;  // 目标在左半部分
                }
                else {
                    left = mid + 1;
                }
            }
            else if (nums[left] > nums[mid]) {  // 右半部分有序
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;  // 目标在右半部分
                }
                else {
                    right = mid - 1;
                }
            }
            else {  // 无法判断哪一部分有序，左指针右移一位
                left++;
            }
        }

        return false;
    }
};
