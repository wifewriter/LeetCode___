#include<iostream>
#include <vector>
using namespace std;
/*k 当前轮次，z城市，y总共轮次*/
int maxGet(int y,int z,int k,vector<int> &aa,vector<int> &bb,vector<int> &cc){
    if(k == y) return 0;
    else{
        int a,b,c;
        if(z == cc[k]){
            /*地点不变*/
            a = aa[k] + maxGet(y,z,k+1,aa,bb,cc);
        } else{
            /*地点改变*/
            b = bb[k] + maxGet(y,cc[k],k+1,aa,bb,cc);
        }
            c = 0 + maxGet(y,z,k+1,aa,bb,cc);

        return max(a, max(b,c));
    }
}

int main(){
//    城市数量，总天数， 初始所在城市。
    int x,y,z;
    cin>>x>>y>>z;
    vector<int> cc; //任务
    vector<int> aa;// 地点不变收益
    vector<int> bb;//地点改变收益
    auto index = y;
    while (index-->0){
        int tt;
        cin>>tt;
        cc.emplace_back(tt);
    }
    index = y;
    while (index-->0){
        int tt;
        cin>>tt;
        aa.emplace_back(tt);
    }
    index = y;
    while (index-->0){
        int tt;
        cin>>tt;
        bb.emplace_back(tt);
    }
    cout << maxGet(y,z,0,aa,bb,cc);

    return 0;
}