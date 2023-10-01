#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int s=0;
        int i = 0;
        int j = height.size() - 1;
        int max=0;
        //ʹ�üбƷ�����ʱ�临�Ӷ�
        //�������֪�����ÿ�μ�һ����������ǽ�С���Ǹ���
        //����ͬ������ʹ���Խ�����ӦԽ��
        while (i < j) {
            s = (j-i) * (height[i] <= height[j] ? height[i] : height[j]);
            if (max < s) {
                max = s;
            }
            height[i] <= height[j] ? i++ : j--;
        }
        return max;
    }
};
