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
 递归 + 回溯 + 溯源
 */
#include <vector>
#include <iostream>

using namespace std;
int x[2] = {0,1};
int y[2] = {1,0};
int maxValue(vector<vector<int>> &matrix,int begin_x,int begin_y,int msize){
    int result = 0;
    if(begin_x == msize-1 and begin_y == msize-1) return matrix[begin_x][begin_y];
    else if (begin_x > msize-1 or begin_y > msize-1){
        return result;
    }
    else{
        vector<vector<int>> temp(matrix);
        vector<vector<int>> temp2(matrix);
        //向右
        int ans1 = matrix[begin_x][begin_y] + maxValue(temp, begin_x + x[0], begin_y + y[0], msize);
        //向下
        int ans2 = matrix[begin_x][begin_y] + maxValue(temp2, begin_x + x[1], begin_y + y[1], msize);
        result = max(ans1,ans2);
        if(ans1 >= ans2 and begin_y+y[0] <= msize-1){
            matrix[begin_x+x[0]][begin_y+y[0]] = 0;
        } else if (begin_x+x[1] <=msize-1){
            matrix[begin_x+x[1]][begin_y+y[1]] = 0;
        }
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
    int num1 = maxValue(matrix,0,0,x);
    int num2 = maxValue(matrix,0,0,x);
    cout << num1 + num2;
    return 0;
}

