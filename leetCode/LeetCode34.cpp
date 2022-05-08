/**
 * 题目:
 *
 */
#include <iostream>
#include "string"
#include <vector>
#include <vector>
using namespace std;

class Solution {
private:
    int findNum(vector<int> & nums,int begin,int end,int target){
        if (begin >= end){
            if(begin == end and nums[begin] == target) return begin;
            else{
                return -1;
            }
        }
        auto middle =(begin+end)/2;
        if(nums[middle] > target){
            return findNum(nums,begin,middle-1,target);
        } else if (nums[middle] < target){
            return findNum(nums,middle+1,end,target);
        } else{
            return middle;
        }
    }
    int findSmallOne(vector<int> nums,int begin ,int end,int target){
        if(begin >= end){
            if(nums[end] == target)return end;
            else return end+1;
        }
        auto middle = (begin + end)/2;
        if (nums[middle] == target){
            return findSmallOne(nums,begin,middle,target);
        } else{
            return findSmallOne(nums,middle+1,end,target);
        }
    }
    int findBigOne(vector<int> nums,int begin, int end , int target){
        if(begin >= end){
            if(nums[begin] == target)return begin;
            else{
                return begin-1;
            }
        }
        auto middle = (begin+end)/2;
        if(nums[middle] == target){
            return findBigOne(nums,middle+1,end,target);
        } else{
            return findBigOne(nums,begin,middle-1,target);
        }
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result{};
        int beginIndex = findNum(nums,0,nums.size()-1,target);
        if(beginIndex == -1)
            return {-1,-1};
        auto first = findSmallOne(nums,0,beginIndex,target);
        auto second = findBigOne(nums,beginIndex,nums.size()-1,target);
        result.emplace_back(first);
        result.emplace_back(second);
        return result;
    }
};
int main(){
    vector<int> aa{5,7,7,8,8,10};
    int target = 8;
    Solution sol;
    auto c = sol.searchRange(aa,target);
    return 0;
}