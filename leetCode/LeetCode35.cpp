/**
 * 题目:
 *
 */
#include <iostream>
#include "string"
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while (left <= right){
            auto middle = (left + right)/2;
            auto num = nums[middle];
            if(num == target) return middle;
            else if(num < target){
                left = middle+1;
            } else{
                right = middle-1;
            }
        }
        return left;
    }
};

int main(){
    vector<int> aa{1,3,5,6};
    int target = 7;
    Solution sol;
    cout<<sol.searchInsert(aa,target);
    return 0;
}