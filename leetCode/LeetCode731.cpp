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

class MyCalendarTwo {
public:
    MyCalendarTwo() {

    }

    bool book(int start, int end) {
        for (auto &[l, r] : overlaps) {
            if (l < end && start < r) {
                return false;
            }
        }
        for (auto &[l, r] : booked) {
            if (l < end && start < r) {
                overlaps.emplace_back(max(l, start), min(r, end));
            }
        }
        booked.emplace_back(start, end);
        return true;
    }
private:
    vector<pair<int, int>> booked;
    vector<pair<int, int>> overlaps;
};

//作者：LeetCode-Solution
//        链接：https://leetcode.cn/problems/my-calendar-ii/solution/wo-de-ri-cheng-an-pai-biao-ii-by-leetcod-wo6n/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

int main(){

    Solution sol;
    cout<<sol
    return 0;
}