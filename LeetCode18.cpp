/**
 * 题目:
 *给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：

0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按 任意顺序 返回答案 。

 

示例 1：

输入：nums = [1,0,-1,0,-2,2], target = 0
输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
示例 2：

输入：nums = [2,2,2,2,2], target = 8
输出：[[2,2,2,2]]
 

提示：

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/4sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include "string"
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() <= 3){
            return {};
        }
        sort(nums.begin(),nums.end(),less<int>());
        int index_0{};
        vector<vector<int>> result{};
        for (int i = 0; i < nums.size()-3 ; ++i) {
            if( i == 0 or nums[i] != index_0){
                //去重
                index_0 = nums[i];
                int index_1{};
                long int targetT0 = target - nums[i];
                for (int j = i+1; j < nums.size()-2 ; ++j) {
                    if(j == i+1 or nums[j] != index_1){
                        index_1 = nums[j];
                        int index_2{};
                        long int targetT1 = targetT0-nums[j];
                        for (int k = j+1; k <nums.size()-1 ; ++k) {
                            if (k == j + 1 or nums[k] != index_2) {
                                index_2 = nums[k];
                                auto l = nums.size() - 1;
                                long int targetT = targetT1- nums[k];

                                while (k < l and nums[l] - targetT > 0) {
                                    l--;
                                }
                                if (k == l) break;
                                if (targetT - nums[l] == 0) {
                                    result.push_back({nums[i], nums[j], nums[k], nums[l]});
                                }
                            }
                        }
                    }
                }
            }
        }
        return result;
    }
};

int main(){
    vector<int> a = {1000000000,1000000000,1000000000,1000000000};
    auto target = 0;
    Solution sol;
    auto c = sol.fourSum(a,target);
    return 0;
}