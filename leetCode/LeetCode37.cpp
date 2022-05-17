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
            for (; j < board[i].size(); ++j) {
                if(board[i][j] == '.'){
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }
    vector<char> findInsertNums(vector<vector<char>> & board,int &x,int &y){
        vector<int> T(10,0);
        T[0] = true;
        for (int i = 0; i < board.size() ; ++i) {
            T[board[x][i] -'0'] = 1;
            T[board[i][y] -'0'] = 1;
        }
        int x1 = 3*(x/3);
        int y1 = 3*(y/3);
        for (int j = 0; j < board.size(); ++j) {
            int tx = x1 + j/3;
            int ty = y1 + j%3;
            T[board[tx][ty] - '0'] = true;
        }
        vector<char> result{};
        for (int k = 1; k < 10 ; ++k) {
            if(!T[k]){
                result.emplace_back(k+'0');
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
            vector<char> insertT = findInsertNums(board,x,y);
            if(insertT.empty()){
                return false;
            }
            for (auto &i : insertT) {

            }
        }
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        mySolveSudoKu(board);
    }
};

int main(){
    vector<vector<char>> board = {{"5","3",".",".","7",".",".",".","."},{"6",".",".","1","9","5",".",".","."},{".","9","8",".",".",".",".","6","."},{"8",".",".",".","6",".",".",".","3"},{"4",".",".","8",".","3",".",".","1"},{"7",".",".",".","2",".",".",".","6"},{".","6",".",".",".",".","2","8","."},{".",".",".","4","1","9",".",".","5"},{".",".",".",".","8",".",".","7","9"}};

    Solution sol;
    cout<<sol
    return 0;
}