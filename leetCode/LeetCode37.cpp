/**
 * 题目:
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <unordered_map>
using namespace std;

class Solution {
private:
    tuple<int,int> judgeBoard(vector<vector<char>> & board){
        int i = 0;
        int j = 0;
        for (; i < board.size(); ++i) {
            for (j=0; j < board[0].size(); ++j) {
                if(board[i][j] == '.'){
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }
    vector<char> findInsertNums(vector<vector<char>> & board,int &x,int &y){
        int T[10] = {0};
        T[0] = 1;
        for (int i = 0; i < board.size() ; ++i) {
            if(board[x][i] != '.'){
                T[board[x][i] -'0'] = 1;
            }
            if(board[i][y] != '.'){
                T[board[i][y] -'0'] = 1;
            }
        }
        int x1 = 3*(x/3);
        int y1 = 3*(y/3);
        for (int j = 0; j < board.size(); ++j) {
            int tx = x1 + j/3;
            int ty = y1 + j%3;
            if(board[tx][ty] != '.'){
                T[board[tx][ty] - '0'] = 1;
            }
        }
        vector<char> result{};
        for (int k = 1; k < 10 ; ++k) {
            if(!T[k]){
                result.push_back(k+'0');
            }
        }
        return result;
    }
    bool mySolveSudoKu(vector<vector<char>> & board){
        auto result = judgeBoard(board);
        if(get<0>(result) == -1){
            return true;
        } else{
            int x = get<0>(result);
            int y = get<1>(result);
            auto insertT = findInsertNums(board,x,y);
            if(insertT.empty()){
                return false;
            }
            for (auto &i : insertT) {
                board[x][y] = i;
                if(!mySolveSudoKu(board)){
                    board[x][y] = '.';
                } else{
                    return true;
                }
            }
            return false;
        }
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        mySolveSudoKu(board);
    }
};
/*递归回溯*/
int main(){
    vector<vector<char>> board{{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};

    Solution sol;
    sol.solveSudoku(board);
    return 0;
}