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
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size() == 1) return pushed[0]==popped[0];
        std::stack<int > st;
        int indexP = 0;
        int indexPo = 0;
        do{
            st.push(pushed[indexP++]);
            while (indexPo < popped.size() and !st.empty() and  popped[indexPo] == st.top()){
                indexPo++;
                st.pop();
            }
        }while(indexP < pushed.size());

        return st.empty() || st.top() == popped[indexPo];
    }
};

int main(){
//    [4,0,1,2,3]
//[4,2,3,0,1]
    vector<int >pushed{4,0,1,2,3};
    vector<int> popped{4,2,3,0,1};
    Solution sol;
    cout<<sol.validateStackSequences(pushed,popped);
    return 0;
}