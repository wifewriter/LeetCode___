/**
 * 题目:
 *给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

 

示例 1:

输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:

输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include "string"
#include <vector>
using namespace std;
/**
 * 寻找正整数最大乘积
 */
//class Solution {
//public:
//    int maxProduct(vector<int>& nums) {
//        int max = nums[0];
//        vector<int> result;
//        int flag = -1;
//        for (int i = 1; i <nums.size() ; ++i) {
//            if(abs(nums[i]-nums[i-1]) == 1){
//                if(flag == -1){
//                    flag = nums[i] - nums[i-1];
//                    max = max>(max*nums[i])?max:(max*nums[i]);
//                } else if((nums[i]-nums[i-1]) != flag){
//                    int temp_max = nums[i]*nums[i-1];
//                    max = max>temp_max?max:temp_max;
//                    flag = nums[i] - nums[i-1];
//                } else{
//                    int temp_max = nums[i]*max;
//                    max = max>temp_max?max:temp_max;
//                }
//            } else{
//                max = max>nums[i]?max:nums[i];
//                flag = -1;
//            }
//        }
//        return max;
//    }
//};

//class Solution {
//public:
//    int maxProduct(vector<int>& nums) {
//        if(nums.size() == 1)
//            return nums[0];
//        int max = nums[0];
//        int result = 0;
//        int pre_max=nums[0]*nums[1];
//        max = max>pre_max?(max>nums[1]?max:nums[1]):(pre_max>nums[1]?pre_max:nums[1]);
//        if(max>pre_max){
//            if(max>nums[1]){
//                result = max;
//                max = nums[1];
//            } else{
//                result = nums[1];
//                max = nums[1];
//            }
//        } else{
//            max = pre_max;
//            result = max;
//        }
//        for (int i = 2; i <nums.size() ; ++i) {
//            if(max > max*nums[i] and pre_max*nums[i] <=max){
//                //当前乘积没有变大
//                pre_max = max*nums[i];
//                int result_t = nums[i]>max?nums[i]:max;
//                result = result>result_t?result:result_t;
//                max = nums[i];
//            } else if(pre_max*nums[i] > max){
//                max = pre_max*nums[i];
//                pre_max = 0;
//            }else{
//                //当前乘积变大
//                max = max*nums[i]>nums[i]?max*nums[i]:nums[i];
//                pre_max = max;
//            }
//        }
//        return result>max?result:max;
//    }
//};
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxF = nums[0], minF = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int mx = maxF, mn = minF;
            maxF = max(mx * nums[i], max(nums[i], mn * nums[i]));
            minF = min(mn * nums[i], min(nums[i], mx * nums[i]));
            ans = max(maxF, ans);
        }
        return ans;
    }
};

int main(){
    vector<int> a = {2,-5,-2,-4,3};
    Solution sol;
    cout << sol.maxProduct(a);
    return 0;
}