#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

int main(){
    int x;
    cin>>x;
    vector<int> arr;
    array<uint8_t,50000> record{0};
    while(x-->0){
        int tt ={};
        cin >>tt;
        if(tt < 50000){
            record[tt] = 1;
        }
        arr.emplace_back(tt);
    }
    int index = 0;
    for(index = 0;index<record.size();index++){
        if(record[index] == 0) break;
    }

    for(int i = 0;i<arr.size();i++){
        if(i ==0 ){
            if(arr[i] < index) {
                cout << arr[i];
            } else{
                cout << index;
            }
        } else{
            if(arr[i] < index){
                cout << " " << arr[i];
            } else{
                cout << " "<<index;
            }
        }
    }

    return 0;
}