#include"headFile.h"
#include <functional>
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;
        function<void(int)> dfs = [&](int i) {
            int d = k - path.size(); // ��Ҫѡ d ����
            if (d == 0) {
                ans.emplace_back(path);
                return;
            }
            // ��ѡ i
            if (i > d) dfs(i - 1);
            // ѡ i
            path.push_back(i);
            dfs(i - 1);
            path.pop_back();
            };
        dfs(n);
        return ans;
    }
};