/**
 * 题目:
 *数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

 

示例 1：

输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
示例 2：

输入：n = 1
输出：["()"]
 

提示：

1 <= n <= 8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/generate-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include "string"
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 0) return {""};
        if(n == 1) return {"()"};
        vector<vector<string>> ss(n+1);
        //初始条件
        ss[0] = {""};
        ss[1] = {"()"};
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j <i ; ++j) {
                for (auto &k : ss[j]) {
                    for(auto &l:ss[i-j-1]){
                        string str = "("+k+")"+l;
                        ss[i].push_back(str);
                    }

                }
            }
        }
        return ss[n];
    }
};
int main(){
    int n = 3;
    Solution sol;
    auto c = sol.generateParenthesis(n);
    return 0;
}