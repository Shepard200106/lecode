#include<iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        //将特例和罗马数字录入
        map<int, string> rom_int = { {1,"I"},{5,"V"},{10,"X"},{50,"L"},{100,"C"},{500,"D"},{1000,"M"},
            {4,"IV"},{9,"IX"},{40,"XL"},{90,"XC"},{400,"CD"},{900,"CM"}};
        int a = num /1000;
        int b = num / 100%10;
        int c = num / 10%10;
        int d = num % 10;
        string ans;
        if (a != 0) {
            while (a > 0) {
                ans += rom_int[1000];
                a--;
            }
        }
        if (b != 0) {
            if (Match(b)) {
                ans += rom_int[Match(b) * 100];
            }else{
                if (b < 4) {
                    while (b > 0) {
                        ans += rom_int[100];
                        b--;
                    }
                }
                else {
                    ans += rom_int[500];
                    b = b - 5;
                    while (b > 0) {
                        ans += rom_int[100];
                        b--;
                    }
                }
            }
        }
        if (c != 0) {
            if (Match(c)) {
                ans += rom_int[Match(c) * 10];
            }
            else {
                if (c < 4) {
                    while (c > 0) {
                        ans += rom_int[10];
                        c--;
                    }
                }
                else {
                    ans += rom_int[50];
                    c = c - 5;
                    while (c > 0) {
                        ans += rom_int[10];
                        c--;
                    }
                }
            }
        }
        if (d != 0) {
            if (Match(d)) {
                ans += rom_int[Match(d)];
            }
            else {
                if (d < 4) {
                    while (d > 0) {
                        ans += rom_int[1];
                        d--;
                    }
                }
                else {
                    ans += rom_int[5];
                    d = d - 5;
                    while (d > 0) {
                        ans += rom_int[1];
                        d--;
                    }
                }
            }
        }
        return ans;
    }
private:
    int Match(int x) {
        switch (x)
        {
        case 1:
            return 1;
        case 4:
            return 4;
        case 5:
            return 5;
        case 9:
            return 9;
        default:
            return 0;
        }
    }
};
