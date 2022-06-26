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
    bool canJump(vector<int>& nums) {
        int n = nums.size()-1;
        vector<int> dp(n+1);
        dp[n] = 1;
        for (int i = n-1;i >=0;i--){
            if(nums[i]>=n-i){
                dp[i] = 1;
            }else{
                if(nums[i] > 0){
                    auto max = max_element(dp.begin()+i+1,dp.begin()+i+nums[i]+1);
                    if(*max > 0 ){
                        dp[i] = 1;
                    }else{
                        dp[i] = 0;
                    }
                }else{
                    dp[i] = 0;
                }
            }
        }
        return dp[0];
    }
};

int main(){

    Solution sol;
    cout<<sol
    return 0;
}