#include<iostream>
#include<string>
#include<stack>
#include<cmath>
#include<vector>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        //ͨ�����������һλ��ͨ��INT_MAX/10��ֹԽ��
        int res = 0;
        while (x != 0) {
            //���λ����10���ڷ�ֹ��������Խ�磬�������10����res����10λʱ�ٳ�10�ͻ�Խ��
            if (abs(res) > INT_MAX/10)return 0;
            //�˴�*10��������λ������10ȡ������ȡ���һλ���е���
            res = res * 10 + x % 10;
            //ȥ���Ѿ�ת�úõ�λ��
            x /= 10;
        }
        return res;
    }
};