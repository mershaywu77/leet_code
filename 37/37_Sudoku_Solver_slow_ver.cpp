// @algorithm @lc id=37 lang=cpp 
// @title sudoku-solver


#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include "algm/algm.h"
using namespace std;
// @test([["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]])=[["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
// @test([[".",".","9","7","4","8",".",".","."],["7",".",".",".",".",".",".",".","."],[".","2",".","1",".","9",".",".","."],[".",".","7",".",".",".","2","4","."],[".","6","4",".","1",".","5","9","."],[".","9","8",".",".",".","3",".","."],[".",".",".","8",".","3",".","2","."],[".",".",".",".",".",".",".",".","6"],[".",".",".","2","7","5","9",".","."]])=[["5","1","9","7","4","8","6","3","2"],["7","8","3","6","5","2","4","1","9"],["4","2","6","1","3","9","8","7","5"],["3","5","7","9","8","6","2","4","1"],["2","6","4","3","1","7","5","9","8"],["1","9","8","5","2","4","3","6","7"],["9","7","5","8","6","3","1","2","4"],["8","3","2","4","9","1","7","5","6"],["6","4","1","2","7","5","9","8","3"]]

class Solution {
/**
* Sudoku's worst time complexity: 3*9! + 3*6! + 3*3! = 1090818 (suppose no number on board).
* Thoughts:
* Generate Three maps `map<int, set>>` with keys from 1 to 9 and sets representing used numbers.
* When an empty cell is visited, put a number existing in all three maps' correspending indecies. 
* Do backtrack on putting and rewinding numbers.
* When found, signalling through a boolean variable.
*/
private:
    map<int, set<int>> row;
    map<int, set<int>> col;
    map<int, set<int>> square;

    // push used number in three maps;
    void initializeBoard(const vector<vector<char>>& board) {
        for (int i=0; i<9; ++i) {
            for (int j=0; j<9; ++j) {
                if (board[i][j] != '.') {
                    int vi = board[i][j] - '0';
                    addNumber(vi, i, j);
                }
            }
        }
    }

    void addNumber(int vi, int i, int j) {
        row[i].insert(vi);
        col[j].insert(vi);
        square[getSquareIndex(i, j)].insert(vi);
    }

    void removeNumber(int vi, int i, int j) {
        row[i].erase(vi);
        col[j].erase(vi);
        square[getSquareIndex(i, j)].erase(vi);
    }

    // the number vi should not be used in any map. 
    bool lookupNumber(int vi, int i, int j){
        if (row[i].find(vi) != row[i].end()) return false;
        if (col[j].find(vi) != col[j].end()) return false;
        set<int> &s = square[getSquareIndex(i, j)];
        if (s.find(vi) != s.end()) return false;
        return true;
    }

    // next index from index i, j
    pair<int, int> nextIndex(int i, int j) {
        pair<int, int> ind = {-1, -1};   
        if (i == 8 && j == 8) {
            return ind;
        }
        if (j == 8) {
            ind = {i+1, 0};
        } else {
            ind = {i, j+1};
        }
        return ind;
    }

    // given the index i, j, return the square index.
    int getSquareIndex(int i, int j) {
        if (i < 3) {
            if (j < 3) return 0;
            if (j >= 3 && j < 6) return 1;
            if (j >= 6 && j < 9) return 2;
        }
        else if (i >= 3 && i < 6) {
            if (j < 3) return 3;
            if (j >= 3 && j < 6) return 4;
            if (j >= 6 && j < 9) return 5;
        }
        else if (i >= 6 && i < 9) {
            if (j < 3) return 6;
            if (j >= 3 && j < 6) return 7;
            if (j >= 6 && j < 9) return 8;
        }
        return -1;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        initializeBoard(board);
        bool found = false;
        dfs(0, 0, board, found);
    }

    void dfs(int i,int j, vector<vector<char>>& board, bool& found) {
        pair<int, int> n_int = nextIndex(i, j);
        if (i == -1 && j == -1) {
            found = true;
            return;
        }
        if (board[i][j] == '.') {
            for (int v=1; v<=9; ++v) {
                if (lookupNumber(v, i, j)) {
                    addNumber(v, i, j);
                    board[i][j] = '0' + v;
                    dfs(n_int.first, n_int.second, board, found);
                    if (!found) {
                        removeNumber(v, i, j);
                        board[i][j] = '.';
                    }
                }
            }
        } else {
            dfs(n_int.first, n_int.second, board, found);
        }
    }
};