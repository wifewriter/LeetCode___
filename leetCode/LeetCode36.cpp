/**
 * 题目:
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <stack>
#include <list>
using namespace std;

class Solution {
private:
    bool judgeRow(vector<vector<char>> &board,int i ,int j,unordered_map<char,int> &T){
        if(board[i][j] == '.') return true;
        if(!T[board[i][j]]){
            T[board[i][j]] = true;
            return true;
        }
        return false;
    }
    bool judgeCol(vector<vector<char>> &board,int i ,int j,unordered_map<char,int> &T2){
        if(board[j][i] == '.') return true;
        if(!T2[board[j][i]]){
            T2[board[j][i]] = true;
            return true;
        }
        return false;

    }
    bool judgeBox(vector<vector<char>> &board,int indexT3x ,int indexT3y,unordered_map<char,int> &T3){
        if(board[indexT3x][indexT3y] == '.') return true;
        if(!T3[board[indexT3x][indexT3y]]){
            T3[board[indexT3x][indexT3y]] = true;
            return true;
        }
        return false;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool flag = true;
        for (int i = 0; i <board.size() ; ++i) {
            unordered_map<char,int> T; //每一行
            unordered_map<char,int> T2;//每一列
            unordered_map<char,int> T3;//每个box
            for (int j = 0; j <board[i].size() ; ++j) {
                int indexT3y = (i-(i/3)*3)*3 + (j-(j/3)*3);
                int indexT3x = (i/3)*3 + (j/3);
                if(!judgeCol(board,i,j,T)){
                    return false;
                }
                if(!judgeRow(board,i,j,T2)){
                    return false;
                }
                if(!judgeBox(board,indexT3x,indexT3y,T3)){
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){

    Solution sol;
    cout<<sol
    return 0;
}