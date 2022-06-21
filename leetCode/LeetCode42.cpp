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
    int trap(vector<int>& height) {
        std::cout<<height.size()<<std::endl;
        vector<int> heightT(height.size(),0);
        auto max = std::max_element(height.begin(),height.end());
        int lmax = 0,rmax = 0;
        for (auto a = height.begin(),b = heightT.begin();  a!=max ; ++a,++b) {
            if(a == height.begin()){
                *b = *a;
                lmax = *a;
                continue;
            }
            if(*a > lmax){
                *b = *a;
                lmax = *a;
            } else{
                *b = lmax;
            }
        }

        for (auto a = height.end()-1,b =heightT.end()-1; a!=max ; --a,--b) {
            if(a == height.end()){
                *b = *a;
                rmax = *a;
                continue;
            }
            if(*a > rmax){
                *b = *a;
                rmax = *a;
            } else{
                *b = rmax;
            }
        }
        heightT[max-height.begin()] = *max;
        int result = 0;
        for (int i = 0; i < height.size(); ++i) {
            result += heightT[i]-height[i];
        }
        for (auto &a : heightT) {
            std::cout<<a;
        }
        return result;
    }
};

int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution sol;
    cout<<sol.trap(height);
    return 0;
}