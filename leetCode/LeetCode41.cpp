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
    int firstMissingPositive(vector<int>& nums) {
        for(int i =0;i<nums.size();i++){
            while(nums[i] != i+1)   {
                if(nums[i] <= 0 or nums[i] > nums.size() or nums[i] == nums[nums[i]-1]){
                    break;
                }
                auto idx = nums[i] -1;
                auto t = nums[i];
                nums[i] = nums[idx];
                nums[idx] = t;
            }
        }
        for(auto i = 0;i<nums.size();i++){
            if(nums[i] != i+1) return i+1;
        }
        return nums.size()+1;
    }
};

int main(){
    vector<int> a = {1,2,0};
    Solution sol;
    cout<<sol.firstMissingPositive(a);
    return 0;
}