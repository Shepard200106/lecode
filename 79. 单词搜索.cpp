#include"headFile.h"
using namespace std;
class Solution {
public:
    void dfs(vector<vector<char>>& board,string word,int i,int j,int k,bool &flag) {
        if (k == word.size()) {
            flag = true;
            return;
        }
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || flag || board[i][j] != word[k]) {
            return;
        }

        char temp = board[i][j];
        board[i][j] = '*';  // Mark the current cell as visited

        dfs(board, word, i + 1, j, k + 1, flag);
        dfs(board, word, i - 1, j, k + 1, flag);
        dfs(board, word, i, j + 1, k + 1, flag);
        dfs(board, word, i, j - 1, k + 1, flag);

        board[i][j] = temp;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        bool flag = false;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == word[0]) {
                    dfs(board, word, i, j, 0, flag);
                    if (flag) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};