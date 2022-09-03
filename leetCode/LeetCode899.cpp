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
    string orderlyQueue(string s, int k) {
        if(k>1){
            sort(s.begin(),s.end());
            return s;
        }
        string result(s);
        for (auto i = 0;i<s.size();i++){
            if(s.compare(result) < 0){
                result = s;
            }
            auto str = *s.begin();
            s.erase(s.begin());
            s+=str;
        }
        return result;
    }
};

int main(){
    string s{"xxqjzq"} ;
    int k = 2;
    Solution sol;
    cout<<sol.orderlyQueue(s,k);
    return 0;
}