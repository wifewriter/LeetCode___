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
    int climbStairs(int n) {
        if(n <=2 )
            return  n;
        vector<int> dp(n);
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2;i < n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n-1];
    }
};

int main(){

    Solution sol;
    cout<<sol
    return 0;
}