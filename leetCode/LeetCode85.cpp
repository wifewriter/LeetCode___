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
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> matrixInt(m,vector<int>(n));
        for(int i = 0;i<m;i++){
            if(matrix[i][0] == '1'){
                matrixInt[i][0] = 1;
            }else{
                matrixInt[i][0] = 0;
            }
        }
        for(int i =0;i<m;i++){
            for(int j = 1;j<n;j++){
                if(matrix[i][j] == '1'){
                    matrixInt[i][j] = matrixInt[i][j-1] +1;
                }else{
                    matrixInt[i][j] = 0;
                }
            }
        }

        vector<vector<int>> dp(m,vector<int>(n,0));
        int result = 0;
        for(int i = 0;i<m;i++){
            for(int j =0;j<n;j++){
                if(matrixInt[i][j] == 0){
                    dp[i][j] = 0;
                }else{
                    int max1 = matrixInt[i][j];
                    int indexii = 1,resulttt=0;
                    int mincol = matrixInt[i][j];
                    for(int ii = i;ii >=0 && matrixInt[ii][j] >0;ii--){
                        mincol = min(matrixInt[ii][j],mincol);
                        max1 = max(mincol*indexii,max1);
                        resulttt = max(max1,resulttt);
                        indexii++;
                    }
                    result = result>resulttt?result:resulttt;
                }
            }
        }
        return result;
    }
};
int main(){
    vector<vector<char>> a = {{'1','0','1','1','1'}, {'0', '1', '0', '1', '0'}, {'1', '1', '0', '1', '1'}, {'1', '1', '0', '1', '1'},
                          {'0', '1', '1', '1', '1'}};
    Solution sol;
    cout<<sol.maximalRectangle(a);
    return 0;
}