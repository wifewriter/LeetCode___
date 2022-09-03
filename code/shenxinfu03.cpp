#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(){
    int x, K;
    vector <int> arr{};
    cin >> x >> K;
    auto t_x = x;
    while (t_x--) {
        int tt{};
        cin >> tt;
        arr.push_back(tt);
    }
    sort(arr.begin(),arr.end(),less<int>());
    unordered_map<int,int> map;
    int res = 0;
    int pre = arr[0] + K;
    for(int i = 1;i<arr.size();i++){
        if(map.empty()){

        }

        if(arr[i]-K > pre){
            res+=1;
            pre = arr[i] + K;
        }

    }
    cout << res;
}