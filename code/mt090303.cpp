#include<iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;
int main(){
    int x;
    cin>>x;
    /*ABCD*/
    vector<char> record(x+1,0);
    /*1 2 2 1 4*/
    vector<int> num(x+1,0);
    num[0] = -1;
    num[1] = 0;
    for(int i = 2;i<x+1;i++){
        int tt{};
        cin>>tt;
        num[i] = tt;
    }
    for(int i = 1;i<x+1;i++){
        char tt{};
        cin>>tt;
        record[i] = tt;
    }
    unordered_map<int ,set<char>> res;

    for(auto i = record.size()-1;i>0;i--){
        int index = i;
        char fuhao = record[index];
        while (index != 0){
            res[index].insert(fuhao);
            index = num[index];
        }
    }
    for(int i = 1;i<=x;i++){
        if(i==1) cout << res[i].size();
        else{
            cout <<" " << res[i].size();
        }
    }
    return 0;
}