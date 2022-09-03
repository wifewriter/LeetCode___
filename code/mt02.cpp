#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

void move(int n,vector<int> &handle){
    vector<int> handleMap(n+1,0);
    handleMap[0] = 1;
    int count = 0;
    for (int j = handle.size()-1; j >= 0 ; --j) {
        if(j == handle.size()-1){
            cout << handle[j];
            handleMap[handle[j]] = 1;
            count++;
        }else if(handleMap[handle[j]] == 0){
            cout << " "<<handle[j];
            handleMap[handle[j]] = 1;
            count++;
        }
    }

    int num = 0;
    for (int i = 0; i < n - count; ++i) {
        while (handleMap[num] != 0){
            num++;
        }
        cout << " " << num++;
    }
}

int main(){

    int len1=0,len2=0;
    std::cin>> len1 >> len2;
    vector<int > handle{};
    while (len2-- > 0){
        int t{};
        cin>>t;
        handle.emplace_back(t);
    }
    move(len1,handle);

    return 0;
}