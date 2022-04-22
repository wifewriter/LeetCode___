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

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include "string"
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

/**
 * 递归算法，不得行
 */
//class Solution {
//private:
//    void pThreeSum(vector<int> & nums,vector<int> &index, set<vector<int>> &result){
//        if(nums.size() < 3) return;
//        if(index[2] >= nums.size()){
//            if (++index[1] >= nums.size() - 1) {
//                if(++index[0] >= nums.size()-2)
//                    return;
//                index[1] = index[0]+1;
//                index[2] = index[1]+1;
//            } else {
//                index[2] = index[1] + 1;
//            }
//        }
//        if ((nums[index[0]] + nums[index[1]] + nums[index[2]]) == 0) {
//            vector<int> t{nums[index[0]], nums[index[1]], nums[index[2]]};
//            sort(t.begin(), t.end(), less<int>());
//            result.insert(t);
//
//            index[1]++;
//            index[2] = index[1] + 1;
//            pThreeSum(nums, index, result);
//
//        } else {
//            index[2]++;
//            pThreeSum(nums, index, result);
//        }
//    }
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        vector<int> index{0,1,2};
//        set<vector<int>> resultSet;
//        pThreeSum(nums,index,resultSet);
//        vector<vector<int>> result(resultSet.begin(),resultSet.end());
//        return result;
//    }
//};

/**
 * 这个方法也超时，
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() <3)
            return {};

        set<vector<int>> resultSet;
        vector<int> index{0, 1, 2};
        while (index[0] <  nums.size()-2){
            if (index[2] >= nums.size()) {
                if (++index[1] >= nums.size() - 1) {
                    if (++index[0] >= nums.size() - 2) {
                        break;
                    }
                    index[1] = index[0]+1;
                    index[2] = index[1] + 1;
                } else {
                    index[2] = index[1] + 1;
                }
            }
            if ((nums[index[0]] + nums[index[1]] + nums[index[2]]) == 0) {
                vector<int> t{nums[index[0]], nums[index[1]], nums[index[2]]};
                sort(t.begin(),t.end(),less<int>());
                resultSet.insert(t);
                index[1] ++;
                index[2] = index[1] + 1;
                continue;
            }
            index[2]++;
        }
        vector<vector<int>> result{resultSet.begin(), resultSet.end()};
        return result;
    }
};

int main(){
    vector<int > b{-1,0,1,2,-1,-4,-2,-3,3,0,4};
    Solution sol;
    auto c = sol.threeSum(b);
    return 0;
}