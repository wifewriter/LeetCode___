/**
 * 题目:
 *给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。

返回这三个数的和。

假定每组输入只存在恰好一个解。

 

示例 1：

输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
示例 2：

输入：nums = [0,0,0], target = 1
输出：0
 

提示：

3 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
-104 <= target <= 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum-closest
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include "string"
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 这个方法只能过90%
 */
//class Solution {
//public:
//    int threeSumClosest(vector<int>& nums, int target) {
//        sort(nums.begin(),nums.end(),less<int>());
//        auto result = pow(10,4)+1;
//        for (int i = 0; i < nums.size() - 2; ++i) {
//            int j = i + 1;
//            bool flag = false;
//            for (; j < nums.size() - 1; ++j) {
//                if (j == i + 1) {
//                    auto k = nums.size() - 1;
//                    while (k > j) {
//                        if (abs(nums[i] + nums[j] + nums[k] - target) < abs(result - target)) {
//                            result = nums[i] + nums[j] + nums[k];
//                            k--;
//                        } else break;
//                    }
//                } else {
//                    auto k = j + 1;
//                    while (k < nums.size()) {
//                        if (!flag and abs(nums[i] + nums[j] + nums[k] - target) > abs(result - target)) {
//                            k--;
//                        } else {
//                            if (!flag) {
//                                flag = true;
//                                result = nums[i] + nums[j] + nums[k];
//                            } else {
//                                break;
//                            }
//                        }
//                    }
//                }
//                if (flag)break;
//            }
//        }
//        return result;
//    }
//};

/**
 * 直接简单穷举+条件退出。
 */
class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end(), less<int>());
        auto result = pow(10, 4) + 1;
        int index0{};
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i == 0 or nums[i] != index0) {
                index0 = nums[i];
                int index1{};
                for (int j = i + 1; j < nums.size() - 1; ++j) {
                    if (j == i + 1 or nums[j] != index1) {
                        index1 = nums[j];
                        auto k = nums.size()-1;
                        while (j < k){
                            auto resultTemp = nums[i] + nums[j] + nums[k];
                            if(resultTemp > target) {
                                //参考的官方去重代码
                                auto k0 = k - 1;
                                // 移动到下一个不相等的元素
                                while (j < k0 && nums[k0] == nums[k]) {
                                    --k0;
                                }
                                k = k0;
                            }
                            else if(resultTemp <target) {
                                // 参考的官方去重代码
                                int j0 = j + 1;
                                // 移动到下一个不相等的元素
                                while (j0 < k && nums[j0] == nums[j]) {
                                    ++j0;
                                }
                                j = j0;
                            }
                            else{
                                return target;
                            }
                            if (abs(result - target) > abs(resultTemp - target)) {
                                result = resultTemp;
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
    vector<int> a = {1,2,4,8,16,32,64,128};
    int target = 82;
    Solution sol;
    cout<<sol.threeSumClosest(a,target);
    return 0;
}