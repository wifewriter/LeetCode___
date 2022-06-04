//
// Created by yy on 22-4-24.
//
/** 2人
 * 7
2 1 12
2 5 8
2 6 6
3 3 5
4 3 13
6 6 5
7 2 1
0 0 0
 递归 + 回溯 + 溯源(记录递归最优的路径)
 */
#include <vector>
#include <iostream>
#include <tuple>

using namespace std;
int xx[2] = {0,1};
int yy[2] = {1,0};
int maxValue(vector<vector<int>> &matrix,int begin_x,int begin_y,int msize,vector<tuple<int,int>> &route){
    int result = 0;
    if(begin_x == msize-1 and begin_y == msize-1){
        return matrix[begin_x][begin_y];
    }
    else if (begin_x > msize-1 or begin_y > msize-1){
        return result;
    }
    else{
        vector<tuple<int,int>> route1{};
        vector<tuple<int,int>> route2{};
        //向右
        int ans1 = matrix[begin_x][begin_y] + maxValue(matrix, begin_x + xx[0], begin_y + yy[0], msize,route1);
        //向下
        int ans2 = matrix[begin_x][begin_y] + maxValue(matrix, begin_x + xx[1], begin_y + yy[1], msize,route2);
        result = max(ans1,ans2);
        if(ans1 >= ans2 and begin_y+yy[0] <= msize-1){
            route1.emplace_back(tuple<int,int>(begin_x,begin_y+yy[0]));
            route.swap(route1);
        } else if (begin_x+xx[1] <= msize-1){
            route2.emplace_back(tuple<int,int>(begin_x+xx[1],begin_y));
            route.swap(route2);
        }
        route1.clear();
        route2.clear();
    }
    return result;
}

int main() {
    int x;
    cin >> x;
    vector<int> temp(x,0) ;
    vector<vector<int>> matrix(x,temp);
    int t_x = x;
    while (t_x--) {
        int xx, yy, val;
        cin >> xx >> yy >> val;
        matrix[xx-1][yy-1] = val;
    }
    vector<std::tuple<int,int>> route{};
    int num1 = maxValue(matrix,0,0,x,route);
    route.emplace_back(tuple<int,int>(0,0));
    for (auto &a : route) {
        int xt = get<0>(a);
        int yt = get<1>(a);
        matrix[xt][yt] = 0;
    }
    int num2 = maxValue(matrix,0,0,x,route);
    cout << num1 + num2;
    return 0;
}

