/**
 * 题目:
 *
 */
#include <iostream>
#include "string"
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
    vector<int> findInsertNums(vector<vector<char>> & board,int &x,int &y){

    }
    bool mySolveSudoKu(vector<vector<char>> & board){
        auto result = judgeBoard(board);
        if(get<0>(result) == -1){
            return true;
        } else{
            int x = get<0>(result);
            int y = get<1>(result);
            vector<int> insertT = findInsertNums(board,x,y);
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

    Solution sol;
    cout<<sol
    return 0;
}