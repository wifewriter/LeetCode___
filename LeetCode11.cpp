//
// Created by Administrator on 2020/3/6.
//
#include <iostream>
#include "string"
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        auto beginIndex = height.begin();
        auto endIndex = height.end()-1;
        int level = 0;
        int maxSize = 0;
        while (endIndex - beginIndex > 0){
            int length = endIndex - beginIndex;
            level = min(*beginIndex,*endIndex);

            int maxSize_t = level*length;
            maxSize = maxSize_t > maxSize?maxSize_t:maxSize;
            if(*beginIndex > *endIndex) endIndex--;
            else beginIndex++;
        }
        return maxSize;
    }
};

int main(){
    vector<int> a{1,8,6,2,5,4,8,3,7};
    Solution b;
    cout<<b.maxArea(a);

    return 0;
}