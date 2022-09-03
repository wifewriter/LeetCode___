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
#include "map"
using namespace std;

class MyCalendarThree {
public:
    MyCalendarThree() {

    }

    int book(int start, int end) {
        int ans = 0;
        int maxBook = 0;
        cnt[start]++;
        cnt[end]--;
        for (auto &[_, freq] : cnt) {
            maxBook += freq;
            ans = max(maxBook, ans);
        }
        return ans;
    }
private:
    //map默认升序
    map<int, int> cnt;
};

//作者：LeetCode-Solution
//        链接：https://leetcode.cn/problems/my-calendar-iii/solution/wo-de-ri-cheng-an-pai-biao-iii-by-leetco-9rif/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
int main(){

    Solution sol;
    cout<<sol
    return 0;
}