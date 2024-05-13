#include"headFile.h"
#include <unordered_set>
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        auto solutions = vector<vector<string>>();
        auto queens = vector<int>(n, -1);
        auto columns = unordered_set<int>();
        auto diagonals1 = unordered_set<int>();
        auto diagonals2 = unordered_set<int>();
        backtrack(solutions, queens, columns, diagonals1, diagonals2,n, 0);
        return solutions;
    }
    void backtrack(vector<vector<string>>& solutions, vector<int>& queens, unordered_set<int>& columns, unordered_set<int>& diagonals1, unordered_set<int>& diagonals2, int n, int row) {
        if (n == row) {
            vector<string>board = generatedBored(queens, n);
            solutions.push_back(board);

        }
        else {
            for (int i = 0; i < n; i++) {
                if (columns.find(i) != columns.end()) {
                    continue;
                }
                int diagonal1 = row - i;
                if (diagonals1.find(diagonal1) != diagonals1.end()) {
                    continue;
                }
                int diagonal2 = row + i;
                if (diagonals2.find(diagonal2) != diagonals2.end()) {
                    continue;
                }
                queens[row] = i;
                columns.insert(i);
                diagonals1.insert(diagonal1);
                diagonals2.insert(diagonal2);
                backtrack(solutions, queens, columns, diagonals1, diagonals2, n, row + 1);
                queens[row] = -1;
                columns.erase(i);
                diagonals1.erase(diagonal1);
                diagonals2.erase(diagonal2);
            }
        }
    }
    vector<string> generatedBored(vector<int> &queens,int n) {
        auto board = vector<string>();
        for (int i = 0; i < n; i++) {
            string row = string(n, '.');
            row[queens[i]] = 'Q';
            board.push_back(row);
        }
        return board;
    }
};