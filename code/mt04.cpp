#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;
int lastres =0;
//9%
int calc(vector<int>&dl,vector<int> &time,int begin){
    if(begin < dl[0]) return -1;

    return lastres;
}

int main(){

    int len1=0,len2=0;
    std::cin>> len1 >> len2;
    int id1  = len1;
    vector<int> dl{};
    while (id1-- > 0){
        int temp{};
        cin >> temp;
        dl.emplace_back(temp);
    }
    vector<int> time;
    int id2 = len1;
    while (id2-- > 0){
        int temp{};
        cin >> temp;
        time.emplace_back(temp);
    }
    int res = calc(dl,time,len2);
    cout<<res;
    return 0;
}