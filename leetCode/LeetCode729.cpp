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

class MyCalendar {
private:
    vector<pair<int,int>> dateApply;
public:
    MyCalendar() {
    }

    bool book(int start, int end) {

        auto index = find_if(dateApply.begin(),dateApply.end(),[&](pair<int,int> &data){
            auto ss = get<0>(data);
            auto ee = get<1>(data);
            return (start < ee and end >= ee) or (start<ss and end > ss) or (start>=ss and end <=ee);
        });
        if(index != dateApply.end()){
            return false;
        } else{
            dateApply.emplace_back(pair<int,int>{start,end});
            return true;
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */


int main(){

    Solution sol;
    cout<<sol
    return 0;
}