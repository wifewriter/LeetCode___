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

/*会超时*/
class FreqStack {
private:
    unordered_map<int,deque<int>> mapFreq;
    unordered_map<int,int> mapRecord;
    vector<int> st;
    int maxFreqNum;
public:
    FreqStack() {
        maxFreqNum = 1;
    }

    void push(int val) {
        st.emplace_back(val);
        if(mapRecord[val] == 0){
            mapRecord[val] ++;
            mapFreq[1].emplace_back(val);
        } else{
            int sum = mapRecord[val];
            mapRecord[val]++;
            maxFreqNum = mapRecord[val]>maxFreqNum?mapRecord[val]:maxFreqNum;
            auto remoit = std::remove(mapFreq[sum].begin(), mapFreq[sum].end(), val);
            mapFreq[sum].erase(remoit,mapFreq[sum].end());
            mapFreq[mapRecord[val]].emplace_back(val);
        }
    }

    int pop() {
        int res{};
        for (auto index = st.end()-1; index > st.begin()-1; --index) {
            if(mapRecord[*index]<maxFreqNum) continue;
            auto ii = find(mapFreq[maxFreqNum].begin(),mapFreq[maxFreqNum].end(),*index);
            if( ii != mapFreq[maxFreqNum].end()){
                /*找到*/
                res = *index;
                index = st.erase(index);
                ii = mapFreq[maxFreqNum].erase(ii);
                mapRecord[res]--;
                if(maxFreqNum != 1 ){
                    mapFreq[maxFreqNum-1].emplace_back(res);
                    if(mapFreq[maxFreqNum].empty()){
                        maxFreqNum -=1 ;
                    }
                }
                break;
            }
        }
        return res;
    }
};


/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

int main(){
    FreqStack sol;
    sol.push(4);
    sol.push(0);
    sol.push(9);
    sol.push(3);
    sol.push(4);
    sol.push(2);
    cout<<sol.pop();
    sol.push(6);
    cout<<sol.pop();
    sol.push(1);
    cout<<sol.pop();
    sol.push(1);
    cout<<sol.pop();
    sol.push(4);
    cout<<sol.pop();
    cout<<sol.pop();
    cout<<sol.pop();
    cout<<sol.pop();
    cout<<sol.pop();
    cout<<sol.pop();

    return 0;
}