/**
 * 题目:
 *给定一个字符串 s 和一些 长度相同 的单词 words 。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。

注意子串要与 words 中的单词完全匹配，中间不能有其他字符 ，但不需要考虑 words 中单词串联的顺序。

 

示例 1：

输入：s = "barfoothefoobarman", words = ["foo","bar"]
输出：[0,9]
解释：
从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
输出的顺序不重要, [9,0] 也是有效答案。
示例 2：

输入：s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
输出：[]
示例 3：

输入：s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
输出：[6,9,12]
 

提示：

1 <= s.length <= 104
s 由小写英文字母组成
1 <= words.length <= 5000
1 <= words[i].length <= 30
words[i] 由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include "string"
#include <vector>
#include <set>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;
/**
 * 超时
 */
//class Solution {
//private:
//    vector<int> fildStrkmp(string &str,string &key){
//        vector<int > index(key.size()+1);
//        index[0] = -1;
//        int i = -1;
//        int j = 0;
//        while (j< key.size()){
//            if(i == -1 or key[i] == key[j]){
//                i++;
//                j++;
//                index[j] = i;
//            } else {
//                i = index[i];
//            }
//        }
//
//        vector<int> result{};
//        j = 0;
//        while (j < str.size()) {
//            auto tj = j;
//            i = 0;
//            while (i == -1 or (i < key.size() and j < str.size())) {
//                if (i == -1 or str[j] == key[i]) {
//                    i++;
//                    j++;
//                } else {
//                    i = index[i];
//                }
//            }
//            if(i == key.size()){
//                result.push_back(j-i);
//
////                j = tj + 1;
//            }
//        }
//        return result;
//    }
//
//    void getTotalStr(string &str,vector<string> &words,set<int> &result){
//        if(words.size() == 1) {
//            auto res = fildStrkmp(str,words[0]);
//            if(res.empty()) return;
//            else {
//                for (auto &i : res) {
//                    result.insert(i);
//                }
//            }
//            return;
//        }
//        for (int i = 0; i <words.size()-1 ; ++i) {
//            for (int j = i+1; j <words.size() ; ++j) {
//                vector<string> tempWords{};
//                for (int k = 0; k < words.size() ; ++k) {
//                    if(k != i and k != j ){
//                        tempWords.push_back(words[k]);
//                    }
//                }
//                tempWords.push_back(words[i]+words[j]);
//                getTotalStr(str,tempWords,result);
////                tempWords.pop_back();
////                tempWords.push_back(words[j]+words[i]);
////                getTotalStr(str,tempWords,result);
//            }
//        }
//    }
//
//public:
//    vector<int> findSubstring(string s, vector<string>& words) {
//        if(s.size() < words.size()*words[0].size())
//            return {};
//        set<int> result{};
//        getTotalStr(s,words,result);
//        vector<int> res{result.begin(),result.end()};
//
//        return res;
//    }
//};

//滑动窗口
//作者：bei-ming-be
//      链接：https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/solution/liang-ge-ha-xi-biao-by-bei-ming-be-5okc/

//class Solution {
//public:
//    vector<int> findSubstring(string s, vector<string>& words) {
//        int n = s.size();
//        int m = words.size(),len=words[0].length();//len表示每个单词的长度
//        int j = m*len; //单词连接后的字符总长度
//        vector<int> ans;
//        unordered_map<string,int> temp_1{};
//        //temp_1记录words信息,key 为单词,value为出现次数
//        for(string x:words){
//            temp_1[x]++;
//        }
//        unordered_map<string,int> temp_2{};//记录当下的单词信息
//        for(int start=0;start+j-1<n;start++){
//            int k=start;//类似于一个指针，用于内层循环
//            while(k-start<j){
//                if(temp_1.count(s.substr(k,len))<=0 || temp_2[s.substr(k,len)]>=temp_1[s.substr(k,len)])break;
//                temp_2[s.substr(k,len)]++;
//                k+=len;
//            }
//            if(temp_1==temp_2) ans.emplace_back(start);
//            temp_2.clear();
//        }
//        return ans;
//    }
//};

//class Solution {
//private:
//    vector<int> res;
//public:
//    vector<int> findSubstring(string s, vector<string>& words) {
//        vector<int> sVec(s.size(),-1);
//        for (auto i = 0;i<words.size();i++){
//            int beginIndex = 0;
//            auto index = s.find(words[i],beginIndex);
//            while(index < s.size()){
//                sVec[index] = i;
//                beginIndex += index+words[i].size();
//                index = s.find(words[i],beginIndex);
//            }
//        }
//        struct queNode{
//            int index;
//            int wordnum;
//        };
//        queue<queNode> que{};
//        for (int i = 0; i < sVec.size(); ++i) {
//            if(sVec[i] != -1){
//                que.push({i,sVec[i]});
//                if(que.size() == words.size()){
//                    vector<int> tt(words.size(),-1);
//                    for (int j = 0; j < que.size(); ++j) {
//                        auto num = que.front();
//                        que.pop();
//                        tt[num.wordnum] = 1;
//                        que.push(num);
//                    }
//                    auto min = *std::min_element(tt.begin(), tt.end());
//                    if (min > -1) {
//                        res.emplace_back(que.front().index);
//                    } else {
//                    }
//                    que.pop();
//                }
//            }
//        }
//        return res;
//    }
//};
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<vector<int>> map{};
        for (auto i =0;i<words.size();i++){
            int index = 0;
            while(index < s.size()){
                auto tt = s.find(words[i],index);
                map[i].emplace_back(tt);
                index += tt + words[i].size();
            }
        }
    }
};

int main(){
    string s = "wordgoodgoodgoodbestword";
    vector<string> aa = {"word","good","best","good"};
    Solution sol;
    auto c = sol.findSubstring(s,aa);
    return 0;
}