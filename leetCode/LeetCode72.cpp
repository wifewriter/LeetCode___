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
    int minDistance(string word1, string word2) {
        int m = word1.size(),n = word2.size();
        if(m == 0 or n == 0){
            return m !=0?m:n;
        }
        vector<vector<int>> dp(m,vector<int>(n));
        if(word1[0] == word2[0]) dp[0][0] = 0;
        else dp[0][0] = 1;
        for (int i = 1;i<m;i++){
            if(word2[0] == word1[i]){
                dp[i][0] = i;
            }else{
                dp[i][0] = dp[i-1][0] + 1;
            }
        }
        for(int j = 1;j<n;j++){
            if(word2[j] == word1[0]){
                dp[0][j] = j;
            }else
            {
                dp[0][j] = dp[0][j-1] +1;
            }
        }
        for(int i = 1;i<m;i++){
            for(int j =1;j <n;j++){
                int a,b,c;
                if(word1[i] == word2[j]){
                    a = dp[i-1][j-1];
                }else{
                    a = dp[i-1][j-1] +1;
                }
                b = dp[i-1][j] +1;
                c = dp[i][j-1] +1;
                int t = min(a,b);
                dp[i][j] = min(t,c);
            }
        }
        return dp[m-1][n-1];
    }
};

int main(){
    string  word1 ="sea",word2 = "eat";
    Solution sol;
    cout<<sol.minDistance(word1,word2);
    return 0;
}