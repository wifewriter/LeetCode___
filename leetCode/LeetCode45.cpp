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
    int jump(vector<int>& nums) {
        int n = nums.size()-1;
        vector<int> dp(n+1);
        dp[n] = 0;
        for (auto i = n-1; i >= 0 ; --i) {
            if (nums[i] >= n - i) {
                dp[i] = 1;
            } else {
                if (nums[i] == 0)
                    dp[i] = n;
                else {
                    auto min = std::min_element(dp.begin() + i +1, dp.begin() + i + nums[i]+1);
                    dp[i] = *min + 1;
                }
            }
        }
        return dp[0];
    }
};

int main(){
    vector<int> a = {1,2,1,1,1};
    Solution sol;
    cout<<sol.jump(a);
    return 0;
}