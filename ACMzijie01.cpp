/**
 * 题目:
 *  4
 *  7
 *  1 1 0 1 0 1 0
 *  1 0 1 0 1 0 1
 *  0 0 0 0 0 0 0
 *  1 1 1 1 0 0 0
 *  输出相邻0的最大个数。
 */
#include <iostream>
#include "string"
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

void findXY(vector<vector<char>> &game, int &x, int &y) {
    for (int i = 0; i < game.size(); ++i) {
        for (int j = 0; j < game[i].size(); ++j) {
            if (game[i][j] == '0') {
                x = i;
                y = j;
                return;
            }
        }
    }
    x = game.size();
    y = game[0].size();
}

//深度
void getDeep(vector<vector<char>> &game, queue<tuple<int, int>> &road, int &indexX, int &indexY, int &result) {
    if (indexX == 0) {
        //右边
        if (indexY < game[0].size() - 1) {
            if (game[indexX][indexY + 1] == '0') {
                road.push(tuple<int, int>(indexX, indexY + 1));
                game[indexX][indexY + 1] = '1';
                result++;
            }
        }
        if(indexY > 0){
            if (game[indexX][indexY - 1] == '0') {
                road.push(tuple<int, int>(indexX, indexY - 1));
                game[indexX][indexY - 1] = '1';
                result++;
            }
        }
        //下边
        if (game[indexX + 1][indexY] == '0') {
            road.push(tuple<int, int>(indexX + 1, indexY));
            game[indexX + 1][indexY] = '1';
            result++;
        }
    }
    else if (indexX == game.size() - 1) {
        //右边
        if (indexY < game[0].size() - 1) {
            if (game[indexX][indexY + 1] == '0') {
                road.push(tuple<int, int>(indexX, indexY + 1));
                game[indexX][indexY + 1] = '1';
                result++;

            }
        }
        if(indexY > 0){
            if (game[indexX][indexY - 1] == '0') {
                road.push(tuple<int, int>(indexX, indexY - 1));
                game[indexX][indexY - 1] = '1';
                result++;
            }
        }
        //上
        if(game[indexX-1][indexY] == '0'){
            road.push(tuple<int, int>(indexX, indexY + 1));
            game[indexX-1][indexY] = '1';
            result++;
        }
    }

    else if (indexY == game[0].size() - 1) {
        if (indexX < game.size() - 1) {
            //xia
            if (game[indexX + 1][indexY] == '0') {
                road.push(tuple<int, int>(indexX + 1, indexY));
                game[indexX + 1][indexY] = '1';
                result++;
            }
        }
        //上
        if(indexX > 0){
            if(game[indexX-1][indexY] == '0'){
                road.push(tuple<int, int>(indexX, indexY + 1));
                game[indexX-1][indexY] = '1';
                result++;
            }
        }
        //左边
        if (game[indexX][indexY - 1] == '0') {
            road.push(tuple<int, int>(indexX, indexY - 1));
            game[indexX][indexY - 1] = '1';
            result++;
        }
    }
    else if(indexY == 0){
        if(indexX < game.size()-1){
            //下边
            if (game[indexX + 1][indexY] == '0') {
                road.push(tuple<int, int>(indexX + 1, indexY));
                game[indexX + 1][indexY] = '1';
                result++;
            }
        }
        //上
        if (indexX > 0) {
            if (game[indexX - 1][indexY] == '0') {
                road.push(tuple<int, int>(indexX, indexY + 1));
                game[indexX - 1][indexY] = '1';
                result++;
            }
        }

        //you
        if (game[indexX][indexY + 1] == '0') {
            road.push(tuple<int, int>(indexX, indexY + 1));
            game[indexX][indexY + 1] = '1';
            result++;
        }

    }
    if (indexX > 0 and indexX < game.size() - 1 and indexY > 0 and indexY < game[0].size() - 1) {
        //左
        if (game[indexX][indexY - 1] == '0') {
            road.push(tuple<int, int>(indexX, indexY - 1));
            game[indexX][indexY - 1] = '1';
            result++;
        }
        //右
        if (game[indexX][indexY + 1] == '0') {
            road.push(tuple<int, int>(indexX, indexY + 1));
            game[indexX][indexY + 1] = '1';
            result++;
        }
        //下
        if (game[indexX + 1][indexY] == '0') {
            road.push(tuple<int, int>(indexX + 1, indexY));
            game[indexX + 1][indexY] = '1';
            result++;
        }
        //上
        if(game[indexX-1][indexY] == '0'){
            road.push(tuple<int, int>(indexX, indexY + 1));
            game[indexX-1][indexY] = '1';
            result++;
        }
    }
}

int main() {
    int x, y;
    vector<vector<char>> game{};
    cin >> x >> y;
    auto t_x = x;
    while (t_x--) {
        vector<char> game_t{};
        auto t_y = y;
        while (t_y--) {
            char t{};
            cin >> t;
            game_t.push_back(t);
        }
        game.push_back(game_t);
    }
    int indexX = 0, indexY = 0, res = 0;
    findXY(game, indexX, indexY);
    queue<tuple<int, int>> road;
    while (indexX < x and indexY < y) {
        road.push(tuple<int, int>(indexX, indexY));
        int result = 0;
        while (!road.empty()) {
            auto top = road.front();
            indexX = get<0>(top);
            indexY = get<1>(top);
            road.pop();
            getDeep(game, road, indexX, indexY, result);
        }

        res = res > result ? res : result;
        findXY(game, indexX, indexY);
    }
    cout << res << endl;
    return 0;
}