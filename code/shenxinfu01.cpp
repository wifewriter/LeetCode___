#include <iostream>
#include <deque>
using namespace std;

int main(){

    deque <int> arr{};
    int num;
    int K;
    while (true){
        cin>>num;
        arr.emplace_back(num);
        if(getchar() == '\n')break;
    }

    K = arr.back();
    arr.pop_back();
    int t_k = K;
    auto first = arr.front();
    arr.pop_front();
    auto second = arr.front();
    arr.pop_front();

    int res = max(first,second);
    if(first>second){
        arr.push_front(first);
        arr.push_back(second);
    } else{
        arr.push_front(second);
        arr.push_back(first);
    }
    do {
        auto first = arr.front();
        arr.pop_front();
        auto second = arr.front();
        arr.pop_front();

        auto tt = max(first, second);
        if (tt == res) {
            t_k--;
        } else {
            t_k = K;
            res = tt;
        }

        if(first>second){
            arr.push_front(first);
            arr.push_back(second);
        } else{
            arr.push_front(second);
            arr.push_back(first);
        }
    } while (t_k > 1);
    cout << res;
}