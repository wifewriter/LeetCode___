/**
 * 题目:
 *
 */
#include <iostream>
#include "string"
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

//class Solution {
//public:
//    int longestValidParentheses(string s) {
//        if(s.size() <=1) return 0;
//        stack<char> ss{};
//        ss.push(s[0]);
//        int result{},result_T{};
//        for (int i = 1; i < s.size(); ++i) {
//            if(s[i] == '('){
//                ss.push(s[i]);
//            }
//            else if(s[i] == ')'){
//                if(!ss.empty() and ss.top() == '('){
//                    ss.pop();
//                    result_T += 2;
//                } else{
//                    result = result>result_T?result:result_T;
//                    result_T = 0;
//                }
//            }
//        }
//        result = result>result_T?result:result_T;
//        stack<char> ss2{};
//        ss2.push(s[0]);
//        int result2{},result_T2{};
//        for (int j = s.size(); j >=0 ; --j) {
//            if(s[j] == ')'){
//                ss.push(s[j]);
//            }
//            else if(s[j] == '('){
//                if(!ss.empty() and ss.top() == ')'){
//                    ss.pop();
//                    result_T2 += 2;
//                } else{
//                    result2 = result2>result_T2?result2:result_T2;
//                    result_T2 = 0;
//                }
//            }
//        }
//        result2 = result2>result_T2?result2:result_T2;
//
//        return result < result2?result:result2;
//    }
//};

//class Solution {
//public:
//    int longestValidParentheses(string s) {
//        if(s.size() <= 1) return 0;
//        unordered_map<unsigned int,int> mapT;
//        mapT[0] = 0;
//        stack<char> ss{};
//        ss.push(s[0]);
//        int result{}, resultT = 0;
//        for (int i = 1; i < s.size(); ++i) {
//            if(s[i] == ')'){
//                if(!ss.empty() and ss.top() == '('){
//                    ss.pop();
//                    resultT +=2;
//                    if(ss.empty()){
//                        mapT[i] = mapT[i-resultT/2];
//                    }
//                } else{
//                    resultT = 0;
//                }
//            } else { // '('
//                ss.push(s[i]);
//            }
//        }
//        return result;
//    }
//};

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() <= 1)
            return 0;
        vector<int> index(s.size(),0);
        unordered_map<int,int> preMap(s.size());
        stack<int> ss{};
        auto result = 0;
        for (int i = 0; i < s.size() ; ++i) {
            preMap[i] = -1;
            if(s[i] == '('){
                ss.emplace(i);
                continue;
            } else {
                if(!ss.empty()){
                    auto t = ss.top();
                    ss.pop();
                    auto sum = 0,j=i-1;
                    for (; j >= t-1 and j>=0 ;) {
                        sum += index[j];
                        if(preMap[j] != -1){
                            while (preMap[j] != -1){
                                j = preMap[j];
                                preMap[i] = j;
                            }
                        } else{
                            j--;
                        }
                    }
                    if(j == t-2){
                        preMap[i] = j+1;
                    }
                    index[i] = sum+2;
                    result = result>index[i]?result:index[i];
                }
            }
        }
        return result;
    }
};

int main(){
    string s{"(()())"};
    Solution sol;
    cout<<sol.longestValidParentheses(s);
    return 0;
}