#include"headFile.h"



/*
�������֪��
1.�����ڲ����˸�������������ֻ���������
    1.���������������
    2.С�������������
2.�Դˣ���������ȥ������������һ��ѭ��������Ϊ���max
�ٽ���һ��ѭ�����������ڵ������������ֵλ���ϵ��������෴��
�����Ӧλ���ϵ������������С��˵����С���������������С��
���������С�������С��˵���������Ѿ����ֽ���λ���µ����ø�
��󷵻�����λ�û������λ�ã�
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 0)   nums[i] = INT_MAX;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (abs(nums[i]) <= nums.size() && nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] *= -1;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0)    return i + 1;
        }
        return nums.size() + 1;
    }
};