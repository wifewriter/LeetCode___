/*给定一个直方图(也称柱状图)，假设有人从上面源源不断地倒水，最后直方图能存多少水量?直方图的宽度为 1。
上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的直方图，在这种情况下，可以接 6 个单位的水（蓝色部分表示水）。 感谢 Marcos 贡献此图。
示例:
输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/volume-of-histogram-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
#include <iostream>
#include "string"
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
using namespace std;

//class Solution {
//public:
//    int myTrap(vector<int> &height,vector<int>::iterator begin,vector<int>::iterator end){
//        int result = 0;
//        bool flag = true;
//        auto index_begin(begin);
//        while (flag && index_begin != end) {
//            auto max_t = max_element(begin, end);
//            int max_loc = max_t - height.begin();
//            if(max_t == height.end()){
//                flag = false;
//            } else{
//                index_begin = max_t;
//                index_begin++;
//            }
//            while (max_loc != 0) {
//                auto min_t = max_element(begin, max_t);
//                int min_loc = min_t - height.begin();
//                if(max_loc - min_loc-1 <= 0) break;
//                int result_t = *min_t * (max_loc - min_loc - 1);
//                for (auto i = min_loc + 1; i < max_loc; i++) {
//                    result_t -= height[i];
//                }
//                result += result_t;
//                max_t = min_t;
//                max_loc = min_loc;
//            }
//            begin = index_begin;
//        }
//        return result;
//    }
//    int myTrap2(vector<int>& height, vector<int>::iterator begin,vector<int>::iterator end){
//        auto max = max_element(height.begin(),height.end());
//        int max_loc = max -height.begin();
//        map<int,int> temp;
//        for (int i = 0; i < max_loc ; ++i) {
//
//        }
//    }
//
//    int trap(vector<int>& height) {
//        return myTrap(height,height.begin(),height.end());
//    }
//};
//class Solution {
//public:
//    int trap(vector<int>& height) {
//        int n = height.size();
//        if (n == 0) {
//            return 0;
//        }
//        vector<int> leftMax(n);
//        leftMax[0] = height[0];
//        for (int i = 1; i < n; ++i) {
//            leftMax[i] = max(leftMax[i - 1], height[i]);
//        }
//
//        vector<int> rightMax(n);
//        rightMax[n - 1] = height[n - 1];
//        for (int i = n - 2; i >= 0; --i) {
//            rightMax[i] = max(rightMax[i + 1], height[i]);
//        }
//
//        int ans = 0;
//        for (int i = 0; i < n; ++i) {
//            ans += min(leftMax[i], rightMax[i]) - height[i];
//        }
//        return ans;
//    }
//};
class Solution {
public:
    int trap(vector<int>& height) {
        int Sum = accumulate(height.begin(), height.end(), 0); // 得到柱子的体积
        int volume = 0; // 总体积和高度初始化
        int high = 1;
        int size = height.size();
        int left = 0; // 双指针初始化
        int right = size - 1;
        while (left <= right) {
            while (left <= right && height[left] < high) {
                left++;
            }
            while (left <= right && height[right] < high) {
                right--;
            }
            volume += right - left + 1; // 每一层的容量都加起来
            high++; // 高度加一
        }
        return volume - Sum; // 总体积减去柱子体积，即雨水总量
    }
};

int main(){
    vector<int> a = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution b;
    cout << b.trap(a);
    return 0;
}