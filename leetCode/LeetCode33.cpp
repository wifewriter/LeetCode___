/**
 * 题目:
 *
 */
#include <iostream>
#include "string"
#include <vector>
using namespace std;
class Solution {
private:
    int findTarget(vector<int> &nums,int begin,int end,int &target){
        if(begin >= end ){
            if(nums[begin] == target){
                return begin;
            } else{
                return -1;
            }
        }
        auto middle = (begin+end)/2;
        if (target > nums[middle]){
            begin = middle+1;
            return findTarget(nums,begin,end,target);
        } else if (target < nums[middle]){
            end = middle-1;
            return findTarget(nums,begin,end,target);
        }
        return middle;
    }
public:
    int search(vector<int>& nums, int target) {
        int i{},index = -1,len = nums.size();
        for (; i < len ; ++i) {
            if(i < len -1 and nums[i+1] < nums[i]) index = i;
            nums.emplace_back(nums[i]);
        }
        auto result = findTarget(nums,index+1,index+len,target);
        if(result >= len) return result -len;
        else return result;
    }
};
int main(){
    vector<int > aa{4,5,6,7,0,1,2};
    Solution sol;
    cout<<sol.search(aa,4);
    return 0;
}