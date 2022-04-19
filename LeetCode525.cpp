//
// Created by Administrator on 2020/3/6.
//
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
int findMaxLength(vector<int>& nums) {
    map<int,int> temp_map = {{0,-1}};
    int index = 0, result = 0;
    for(int i = 0; i < nums.size(); ++i)
    {
        nums[i] == 0? --index : ++index;
        auto flag = temp_map.find(index);
        if(flag!=temp_map.end())
            result = max(result, i - temp_map[index]);
        else
            temp_map.insert(std::pair<int,int>(index,i));
    }
    return result;
}
};

int main(){

    vector<int> nums = {0,0,1,1,0};
    Solution a;
    std::cout <<a.findMaxLength(nums);
    return 0;
}