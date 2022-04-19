/*给你一个整数数组 nums 和一个整数 target 。

向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

 

示例 1：

输入：nums = [1,1,1,1,1], target = 3
输出：5
解释：一共有 5 种方法让最终目标和为 3 。
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
示例 2：

输入：nums = [1], target = 1
输出：1
 

提示：

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/target-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
#include <iostream>
#include "string"
#include <vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int len = nums.size();
        if(len ==1 and (target == nums[0] or target == -nums[0]))return 1;
        else if(len == 1 and target != nums[0])return 0;
        return findWaysByIndex(nums,target,len-1);
    }

private:
    int findWaysByIndex(vector<int>& nums,int target,int index){
        if (index == 0) {
            if(target == nums[index] or target == -nums[index]){
                if(target == 0)return 2;
                else
                return 1;
            }
            else return 0;
        } else{
            return findWaysByIndex(nums,target-nums[index],index-1) + findWaysByIndex(nums,target+nums[index],index-1);
        }
    }
};

int main(){
    vector<int> a = {0,1};
    Solution sol;
    cout<< sol.findTargetSumWays(a,1);

    return 0;
}