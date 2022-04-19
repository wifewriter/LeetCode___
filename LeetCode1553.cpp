/**
 * 题目:
 *厨房里总共有 n 个橘子，你决定每一天选择如下方式之一吃这些橘子：

吃掉一个橘子。
如果剩余橘子数 n 能被 2 整除，那么你可以吃掉 n/2 个橘子。
如果剩余橘子数 n 能被 3 整除，那么你可以吃掉 2*(n/3) 个橘子。
每天你只能从以上 3 种方案中选择一种方案。

请你返回吃掉所有 n 个橘子的最少天数。

 

示例 1：

输入：n = 10
输出：4
解释：你总共有 10 个橘子。
第 1 天：吃 1 个橘子，剩余橘子数 10 - 1 = 9。
第 2 天：吃 6 个橘子，剩余橘子数 9 - 2*(9/3) = 9 - 6 = 3。（9 可以被 3 整除）
第 3 天：吃 2 个橘子，剩余橘子数 3 - 2*(3/3) = 3 - 2 = 1。
第 4 天：吃掉最后 1 个橘子，剩余橘子数 1 - 1 = 0。
你需要至少 4 天吃掉 10 个橘子。
示例 2：

输入：n = 6
输出：3
解释：你总共有 6 个橘子。
第 1 天：吃 3 个橘子，剩余橘子数 6 - 6/2 = 6 - 3 = 3。（6 可以被 2 整除）
第 2 天：吃 2 个橘子，剩余橘子数 3 - 2*(3/3) = 3 - 2 = 1。（3 可以被 3 整除）
第 3 天：吃掉剩余 1 个橘子，剩余橘子数 1 - 1 = 0。
你至少需要 3 天吃掉 6 个橘子。
示例 3：

输入：n = 1
输出：1
示例 4：

输入：n = 56
输出：6
 

提示：

1 <= n <= 2*10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-days-to-eat-n-oranges
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include "string"
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<int, int> memo;

public:
    int minDays(int n) {

    /* 这个时间复杂度太大。n^n
     * memo[0] = -1;
        memo[1] = 1;
        for (int i = 2; i <=n ; ++i) {
            memo[i] = memo[i-1]+1;
            if(i%2 == 0) {
                memo[i] = min(memo[i],memo[i/2]+1);
            }
            if(i%3 == 0){
                memo[i] = min(memo[i],memo[i/3]+1);
            }
        }
        return memo[n];*/
        if (n <= 1) {
            return n;
        }
        if (memo.count(n)) {
            return memo[n];
        }
        return memo[n] = min(n % 2 + 1 + minDays(n / 2), n % 3 + 1 + minDays(n / 3));
    }
};

int main(){
    Solution sol;
    cout<<sol.minDays(100);
    return 0;
}