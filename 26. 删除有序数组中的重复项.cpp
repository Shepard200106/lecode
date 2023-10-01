#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0, ind = 1;
        int t = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == t) {
                continue;
            }
            else {
                t = nums[i];
                nums[ind] = t;
                ind++;
            }
        }
        return ind;
    }
};