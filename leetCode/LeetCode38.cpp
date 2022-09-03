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
    string countAndSay(int n) {
        if(n==1) return "1";
        if(n==2) return "11";
        else{
            auto result = countAndSay(n-1);
            int num = 0;
            auto pre = result[0];
            string res{};
            for (auto i = 0;i<result.size();i++){
                if(i != 0 ){
                    if(result[i] != pre){
                        res += std::to_string(num);
                        res += pre;
                        num = 1;
                        pre = result[i];
                    } else{
                        num++;
                    }
                }else{
                    pre = result[i];
                    num = 1;
                }
            }
            res += std::to_string(num);
            res += pre;
            return res;
        }
    }
};

int main(){
    int num = 5;
    Solution sol;
    cout<<sol.countAndSay(num);
    return 0;
}