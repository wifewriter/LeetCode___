/*
你有 4 张写有 1 到 9 数字的牌。你需要判断是否能通过 *，/，+，-，(，) 的运算得到 24。

示例 1:

输入: [4, 1, 8, 7]
输出: True
        解释: (8-4) * (7-1) = 24
示例 2:

输入: [1, 2, 1, 2]
输出: False
        注意:

除法运算符 / 表示实数除法，而不是整数除法。例如 4 / (1 - 2/3) = 12 。
每个运算符对两个数进行运算。特别是我们不能用 - 作为一元运算符。例如，[1, 1, 1, 1] 作为输入时，表达式 -1 - 1 - 1 - 1 是不允许的。
你不能将数字连接在一起。例如，输入为 [1, 2, 1, 2] 时，不能写成 12 + 12 。*/

#include "string"
#include <vector>
#include <iostream>

using namespace std;

//copy 自 https://leetcode-cn.com/problems/24-game/solution/ying-gai-shi-man-hao-li-jie-de-si-lu-liao-by-xiao_/ bigwindlee用户

//bigwindlee 这位大佬的思路情绪，代码更容易看懂。学习了。
class Solution {
public:
    bool judgePoint24(vector<int>& nums)
    {
        vector<double> digits;
        for (int num : nums) {
            digits.push_back(num);
        }
        return backTrack(digits);
    }

    bool backTrack(vector<double>& digits)
    {
        int n = (int)digits.size();
        if (n == 1) {
            return abs(digits[0] - 24) < 0.001;
        }

        // 任选2个数字的“组合”做合并，“组合”的意思是不关心顺序，不是排列。
        // 所以j的下标从 i+1 开始。
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                vector<double> newDigits;

                // i和j是要合并的2个数，剩下的所有数字要进入newDigits
                // i和j合并之后也要进入newDigits，用newDigits做递归。
                for (int k = 0; k < n; ++k) {
                    if (k == i || k == j)
                        continue;
                    newDigits.push_back(digits[k]);
                }

                for (int op = 0; op < 6; ++op) { // 合并的2个数要尝试所有可能的运算符
                    newDigits.push_back(calculate(op, digits[i], digits[j]));
                    if (backTrack(newDigits))
                        return true;
                    newDigits.pop_back();
                }
            }
        }
        return false;
    }

    double calculate(int op, double a, double b)
    {
        // 因为减法和除法不满足交换律，因此定义6中运算符：
        // 0: a+b
        // 1: a-b
        // 2: b-a
        // 3: a*b
        // 4: a/b
        // 5: b/a
        if (op == 0)
            return a + b;
        else if (op == 1)
            return a - b;
        else if (op == 2)
            return b - a;
        else if (op == 3)
            return a * b;
        else if (op == 4)
            return a / b;

        return b / a;
    }
};
int main(){
    vector<int> input_v = {4,1,8,7};
    Solution a;
    cout<< a.judgePoint24(input_v);
    return 0;
}