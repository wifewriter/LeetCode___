#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int x;
    cin>>x;
    vector<long> arr;
    while (x-- > 0){
        int c = 0;
        cin>>c;
        arr.emplace_back(c);
    }
    sort(arr.begin(),arr.end(),std::less<int>());
    int res = 1;
    int len = 1;
    auto pre = arr[0];
    for(int i = 1;i<arr.size();i++){
        if(arr[i] == pre)continue;
        if(arr[i] == pre+1){
            pre = arr[i];
            len+=1;
        } else{
            res = max(res,len);
            len = 1;
            pre = arr[i];
        };
    }
    cout << res;
}