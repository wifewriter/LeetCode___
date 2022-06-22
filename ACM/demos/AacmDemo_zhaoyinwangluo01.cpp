//
// Created by yy on 22-4-24.
//
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int timesCalc(vector<int> &first,vector<int> &second) {
    if(first == second) return 0;
    int result = 0;
    vector<int> temp{};
    unordered_map<int,bool> map;
    int i = 0,j = 0;
    for (; i < first.size() and j < second.size() ; ) {
        if(first[i] == second[j]){
            i++;
            j++;
            continue;
        } else if(!map[first[i]]){
            map[second[j]] = true;
            j++;
            result++;
        } else if(map[first[i]]){
            i++;
        }
    }
    return result;
}
int main() {
    vector<int > first;
    vector<int > second;
    int x {};
    cin >> x;
    auto t_x = x;
    while (t_x--){
        int t {};
        cin>> t;
        first.emplace_back(t);
    }
    t_x = x;
    while (t_x--){
        int t{};
        cin>>t;
        second.emplace_back(t);
    }
    cout << timesCalc(first,second);
    //code insert here
}

