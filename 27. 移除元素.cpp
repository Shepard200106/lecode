#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    int removeElement(vector<int>&nums, int val) {
        int index = 0;
        vector<int>::iterator it = nums.begin();
        if (nums.size() == 0)return 0;
        while(it!=nums.end()) {
            if (*it == val) {
                it = nums.erase(it);
            }
            else {
                it++;
            }
        }
        return nums.size();
    }
};
//k¿ìÂıÖ¸Õë·¨
/*class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowindex=0;
        int fastindex=0;
        for(;fastindex<nums.size();fastindex++){
            if(nums[fastindex]!=val){
                nums[slowindex]=nums[fastindex];
                slowindex++;
            }
        }
        return slowindex;
    }
};*/