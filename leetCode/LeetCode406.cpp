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
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        list<vector<int>> list;
        std::sort(people.begin(),people.end(),[&](vector<int> &a,vector<int>b){
            return a[0] > b[0] or (a[0] == b[0] and a[1] < b[1]);
        });
        for(auto &a: people){
            int index = std::min(a[1],static_cast<int>(list.size()));
            auto indexit = list.begin();
            while (index-- > 0){
                indexit++;
            }
            list.insert(indexit,a);
        }
        return vector<vector<int>>(list.begin(),list.end());
    }
};

int main(){
    vector<vector<int>> a ={{9,0},{7,0}, {1, 9}, {3, 0}, {2, 7}, {5, 3}, {6, 0}, {3, 4}, {6, 2},{5,2}};
    Solution sol;
    sol.reconstructQueue(a);
    return 0;
}