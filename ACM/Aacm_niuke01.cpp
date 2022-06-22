//
// Created by yy on 22-4-24.
//
/**
 * 题目描述：
 *[编程题]小美的送花线路
时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 256M，其他语言512M
小美是美团的一名鲜花快递员，鲜花是一种保质期非常短的商品，所以需要尽快送到客户手中，公司对于骑手的一个要求就是要规划送花的线路，使得骑手送完所有订单走的路程尽可能少。(骑手开始派送时带走了所有需要派送的花，不必每单后返回花店，路程结算是从花店出发，到送完最后一名客户为止，不计算从最后一名客户家回到花店的时间)
       公司对于骑手的绩效评价是取决于两个指标，一是从花店到所有客户地址的距离之和，另一个是骑手实际走的路程。
      设花店始终位于1号位置，客户共有n-1个，其编号为2~n。令dis(i,j)表示i号位置到j号位置的距离，即分别计算, 和骑手实际所走的最短路程。
      为了简化问题，我们约束这n个位置构成的是一棵树，即只有n-1条边在其中互相连接，且保证n个点彼此连通。

输入描述:
输出第一行包含一个正整数n，即花店和客户的总数。(1<=n<=30000)
接下来有n-1行，每行有三个整数u,v,w，表示在u和v之间存在一条距离为w的道路。(1<=w<=1000)

输出描述:
输出包含两个整数，中间用空格隔开，分别表示花店到所有客户地址的距离之和和骑手实际走的路程。
输入例子1:
5
1 2 3
1 3 1
1 4 2
2 5 1
输出例子1:
10 10
 */
#include <vector>
#include <iostream>
#include <tuple>
using namespace std;
int main() {
    int x;
    cin >> x;

//    并查集
    vector<tuple<int,int>> route(x,tuple<int,int>(-1,0));
    vector<int> routeval(x,0);
//    并查集数值
    int total_1{};
    int total_2{};
    auto t_x = x-1;
    while (t_x--) {
        int xx,yy,vv;
        cin >> xx >>yy >>vv;
        route[yy-1] = tuple<int,int>(xx-1,vv);
        if(xx == 1){
            routeval[yy-1] = vv;
        }
        total_2 += vv*2;
    }
    for (int i = 1; i < route.size() ; ++i) {
        int res{};
        bool  flag = false;
        auto tt = i;
        while ((get<0>(route[tt]) != 0 or flag) and tt != 0){
            res += get<1>(route[tt]);
            tt = get<0>(route[tt]);
            flag = true;
        }
        if(flag) routeval[i] = res;
    }

    int maxVal{};
    for (int j = 1; j <routeval.size() ; ++j) {
        total_1 += routeval[j];
        maxVal = maxVal>routeval[j]?maxVal:routeval[j];
    }
    cout << total_1 << " " <<total_2-maxVal;
}

