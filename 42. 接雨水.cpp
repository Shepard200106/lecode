#include"headFile.h"
/*
* ˫ָ�뷨�����������м���б�����
* ���������С���ұ������ô��ָ���ƶ������ÿ����Ĵ�ˮ��
* ͬ���ұ�
* ��ˮҪ��������ǽ����ˮ������Сǽ�߶��йأ�
* �׹̶�Ϊ1����ΪС����һ�൫�Ǹ��ڱ����ǽ�ߣ�
* ���Ϊ�߼���ˮ���߶ȣ�
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        int maxlelt = height[0];
        int maxright = height[n - 1];
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            maxlelt = max(maxlelt, height[left]);
            maxright = max(maxright, height[right]);
            if (maxlelt < maxright) {
                ans += maxlelt - height[left];
                left++;
            }
            else {
                ans += maxright - height[right];
                right--;
            }
        }
        return ans;
    }
};
