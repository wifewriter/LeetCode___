/**
 * 题目:
 *给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



 

示例 1：

输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
示例 2：

输入：digits = ""
输出：[]
示例 3：

输入：digits = "2"
输出：["a","b","c"]
 

提示：

0 <= digits.length <= 4
digits[i] 是范围 ['2', '9'] 的一个数字

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include "string"
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<char ,vector<string>> numTocharVec{
            pair<char, vector<string>>('2',{"a","b","c"}),
            pair<char, vector<string>>('3',{"d","e","f"}),
            pair<char, vector<string>>('4',{"g","h","i"}),
            pair<char, vector<string>>('5',{"j","k","l"}),
            pair<char, vector<string>>('6',{"m","n","o"}),
            pair<char, vector<string>>('7',{"p","q","r","s"}),
            pair<char, vector<string>>('8',{"t","u","v"}),
            pair<char, vector<string>>('9',{"w","x","y","z"}),
    };
public:
    vector<string> letterCombinations(string digits) {
        vector<string > result = {};
        if(digits.empty()){
            return {};
        }
        if(digits.size() == 1){
            return numTocharVec[digits[0]];
        }
        auto first = digits[0];
        digits.erase(digits.begin());
        for (auto &i : numTocharVec[first]) {
            for (auto &j : letterCombinations(digits)) {
                result.push_back({i+j});
            }
        }
        return result;
    }
};

int main(){
    string input = "23";
    Solution sol;
    auto c = sol.letterCombinations(input);
    return 0;
}