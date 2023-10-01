#include<iostream>
#include<vector>
#include<algorithm>
#include <map>
#include <unordered_map>
using namespace std;
class Solution{
public:
    vector<string> letterCombinations(string digits) {
        vector<string>combination;
        if (digits.empty()) {
            return combination;
        }
        unordered_map<char, string> digitToLetters = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        backtrack(digits,0,"",digitToLetters,combination);
        return combination;
    }
    void backtrack(const string& digits, int index, string currentCombination,
        const unordered_map<char, string>& digitToLetters,
        vector<string>& combinations) {
        if (index == digits.length()) {
            combinations.push_back(currentCombination);
            return;
        }
        char currentDigit = digits[index];
        for (char letter : digitToLetters.at(currentDigit)) {
            backtrack(digits, index + 1, currentCombination + letter,digitToLetters,combinations);
        }
        
    }
};