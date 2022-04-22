/**
 * 题目:
 *给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

示例 1：

输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
示例 2：

输入：nums = []
输出：[]
示例 3：

输入：nums = [0]
输出：[]
 

提示：

0 <= nums.length <= 3000
-105 <= nums[i] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include "string"
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3)
            return {};
        sort(nums.begin(),nums.end(),less<int>());
        vector<vector<int>> result;
        auto index_0 = pow(10,5)+1,index_1 = pow(10,5)+1;
        for (int i = 0; i < nums.size()-2 ; ++i) {
            if(i == 0 or nums[i] != index_0){
                index_0 = nums[i];
                auto k = nums.size()-1;
                for (int j = i + 1; j < nums.size() - 1 ; ++j) {
                    if(j == i+1 or nums[j] != index_1){
                        index_1 = nums[j];
                        for (; k > j ; --k) {
                            if( nums[j]+nums[k] <= -nums[i]){
                                break;
                            }
                        }
                        if(k==j) break;
                        if((nums[i]+nums[j]+nums[k]) == 0){
                            result.push_back({nums[i],nums[j],nums[k]});
                        }
                    }
                }
            }
        }
        return result;
    }
};

int main(){
    vector<int> a{-1,0,1,2,-1,-4};
    Solution sol;
    auto c = sol.threeSum(a);
    return 0;
}