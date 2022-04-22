/**
 * 题目:
 *给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
 

示例 1：

输入：s = "()"
输出：true
示例 2：

输入：s = "()[]{}"
输出：true
示例 3：

输入：s = "(]"
输出：false
示例 4：

输入：s = "([)]"
输出：false
示例 5：

输入：s = "{[]}"
输出：true
 

提示：

1 <= s.length <= 104
s 仅由括号 '()[]{}' 组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include "string"
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
    unordered_map<string,bool > judgeEuqalMap{
        pair<string,bool>("{}",true),
        pair<string,bool>("()",true),
        pair<string,bool>("[]",true),
    };

    bool judgeEqual(char &i,char &q){
        string ss{i};
        ss+=q;
        return judgeEuqalMap[ss];
    }

public:
    bool isValid(string s) {
        stack<char> ss;
        for (auto i = s.end()-1;(i -s.begin()) >=0;i--) {
            if(ss.empty()){
                ss.push(*i);
                continue;
            }
            auto t = ss.top();
            if(judgeEqual(*i,t)){
                ss.pop();
                continue;
            } else{
                ss.push(*i);
            }
        }
        return ss.empty();
    }
};
int main(){
    string aa = "()";
    Solution sol;
    cout<<sol.isValid(aa);
    return 0;
}