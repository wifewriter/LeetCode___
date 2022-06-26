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
    int maxSubArray(vector<int>& nums) {
        vector<int> a(nums.size());
        a[0] = nums[0];
        for (int i = 1;i<nums.size();i++){
            if(a[i-1] <0 and nums[i] >=0){
                a[i] = nums[i];
            }
            else if(nums[i] + a[i-1] > 0) {
                a[i] = a[i-1] + nums[i];
            }else{
                a[i] = nums[i];
            }
        }
        return *max_element(a.begin(),a.end());
    }
};

int main(){
    vector<int> a = {5,4,-1,7,8};
    Solution sol;
    cout<<sol.maxSubArray(a);
    return 0;
}