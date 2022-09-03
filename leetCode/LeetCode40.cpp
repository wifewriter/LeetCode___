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
    vector<int> candidates;
    vector<vector<int>> res;
    vector<int> path;
public:
    void DFS(int start, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size() && target - candidates[i] >= 0; i++) {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            path.push_back(candidates[i]);
            // 元素不可重复利用，使用下一个即i+1
            DFS(i + 1, target - candidates[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        DFS(0, target);
        return res;
    }
};
int main(){
    vector<int> a{4,4,4,3,4,2,2};
    auto dd = a.size();
    int target = 4;
    Solution sol;
    auto c  = sol.combinationSum2(a,target);
    return 0;
}