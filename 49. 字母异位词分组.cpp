#include"headFile.h"
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> temp;
        for (auto& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            temp[key].emplace_back(str);
        }
        for (auto it = temp.begin(); it != temp.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};