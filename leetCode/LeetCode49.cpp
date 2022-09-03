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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size() <=1) return {strs};
        unordered_map<string,vector<string>> map;
        for (int i = 0; i < strs.size(); ++i) {
            auto tt = strs[i];
            sort(tt.begin(),tt.end());
            if(map.count(tt) != 0 ){
                map[tt].emplace_back(strs[i]);
            } else{
                map[tt] = vector<string>({strs[i]});
            }
        }
        vector<vector<string>> res{};
        for (auto &i : map) {
            res.push_back(i.second);
        }
        return res;
    }
};

int main(){
    vector<string> a{"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution sol;
    auto c = sol.groupAnagrams(a);
    return 0;
}