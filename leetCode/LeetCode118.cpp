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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res{};
        res.emplace_back(vector<int>(1,1));
        if(numRows==1) return res;
        res.emplace_back(vector<int>(2,1));
        for(int i = 3;i<=numRows;i++){
            vector<int> tt(i,1);
            tt[0] = 1;
            tt[i-1] = 1;
            for(int j = 1;j<i-1;j++){
                tt[j] = res[i-2][j-1] + res[i-2][j];
            }
            res.emplace_back(tt);
        }
        return res;
    }
};

int main(){
    int a=3;
    Solution sol;
   auto c = sol.generate(a);
    return 0;
}