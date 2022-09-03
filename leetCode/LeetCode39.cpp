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
private:
    vector<vector<int>> result{};
    bool myconbinationSum(vector<int>& candidates,int target,vector<int> &temp,int j){
        if( target < 0 ){
            return false;
        } else if (target == 0){
            return true;
        } else{
            for (int i = j; i < candidates.size(); ++i) {
                temp.emplace_back(candidates[i]);
                if (!myconbinationSum(candidates, target - candidates[i], temp,i)) {
                    temp.pop_back();
                } else {
                    result.emplace_back(temp);
                    temp.pop_back();
                    continue;
                }
            }
            return false;
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        vector<int> temp{};
        myconbinationSum(candidates,target,temp,0);
        return result;
    }
};

int main(){
    vector<int> a{2,3,6,7};
    int target = 7;
    Solution sol;
    auto c  = sol.combinationSum(a,target);
    return 0;
}