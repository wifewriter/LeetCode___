/**
 * 题目:
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <stack>
#include <list>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() < 1) return 0;
        vector<int> dp(s.size(),0);
        dp[0] = 1;
        for (int i =1;i<s.size();i++){
            int num = 1;
            int index = i-1;
            int epoch = dp[i-1];
            while(index >=0 and s[i] != s[index--] and --epoch >= 0){
                num++;
            }
            dp[i] = num;
        }
        return *std::max_element(dp.begin(),dp.end());
    }
};

int main(){
    string  s("abcabcbb");
    Solution sol;
    cout<<sol.lengthOfLongestSubstring(s);
    return 0;
}