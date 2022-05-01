/**
 * 题目:
 *
 */
#include <iostream>
#include "string"
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        vector<int> temp{nums.begin(), nums.end()};
        sort(temp.begin(), temp.end(), greater<int>());
        if (temp == nums) {
            sort(nums.begin(), nums.end(), less<int>());
            return;
        }
        auto maxIndex = nums.end()-2;
        auto numT = nums.back();
        while (distance(nums.begin(),maxIndex) >=0){
            if(*maxIndex < numT){
                auto tempNum = *maxIndex;
                sort(maxIndex,nums.end(),less<int>());
                auto i = maxIndex;
                for (;  i<nums.end() ; ++i) {
                    if(*i > tempNum) {
                        break;
                    }
                }
                swap(*maxIndex,*i);
                sort(maxIndex+1,nums.end(),less<int>());
                return;
            } else{
                numT = *maxIndex;
                maxIndex--;
            }
        }
   }
};

int main() {
    vector<int> aaa{2,3,1};
//    vector<int> aaa{5,4,7,5,3,2};
    Solution sol;
    sol.nextPermutation(aaa);
    return 0;
}