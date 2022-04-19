/**
 * 题目:
 *给你一个整数数组 nums ，设计算法来打乱一个没有重复元素的数组。打乱后，数组的所有排列应该是 等可能 的。

实现 Solution class:

Solution(int[] nums) 使用整数数组 nums 初始化对象
int[] reset() 重设数组到它的初始状态并返回
int[] shuffle() 返回数组随机打乱后的结果
 

示例 1：

输入
["Solution", "shuffle", "reset", "shuffle"]
[[[1, 2, 3]], [], [], []]
输出
[null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]

解释
Solution solution = new Solution([1, 2, 3]);
solution.shuffle();    // 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。例如，返回 [3, 1, 2]
solution.reset();      // 重设数组到它的初始状态 [1, 2, 3] 。返回 [1, 2, 3]
solution.shuffle();    // 随机返回数组 [1, 2, 3] 打乱后的结果。例如，返回 [1, 3, 2]
 

提示：

1 <= nums.length <= 200
-106 <= nums[i] <= 106
nums 中的所有元素都是 唯一的
最多可以调用 5 * 104 次 reset 和 shuffle

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shuffle-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include "string"
#include <vector>
using namespace std;

class Solution {
public:
    Solution(vector<int>& nums) {
        pre_len = nums.size();
        pre.assign(nums.begin(),nums.end());
        now.assign(nums.begin(),nums.end());
    }

    vector<int> reset() {
        now.assign(pre.begin(),pre.end());
        return now;
    }

    vector<int> shuffle() {
        for (int i = 0; i < pre_len; ++i) {
            int temp = now[i];
            int index_t = i+rand()%(pre_len -i);
            now[i] = now[index_t];
            now[index_t] = temp;
        }
        return now;
    }

    friend ostream &operator <<(ostream &out,Solution &a);

private:
    vector<int> pre;
    int pre_len;
    vector<int> now;
};

ostream &operator <<(ostream &out,Solution &a){
    for(auto &i: a.now){
        out<<i;
    }
    return out;
}
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

int main(){
    vector<int> a = {1,2,3};
    Solution sol(a);
    cout<<sol<<endl;
    sol.shuffle();
    cout<<sol<<endl;
    sol.reset();
    cout<<sol<<endl;
    sol.shuffle();
    cout<<sol<<endl;
    return 0;
}