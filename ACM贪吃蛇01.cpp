//
// Created by yy on 22-4-22.
//
/**
 *
 * 输入格式：
 * 3 4
 * ....
 * .*$.
 * $...
 * WASDDA
 */
#include <iostream>
#include <cstdio>
#include<vector>
#include<string>

using namespace std;

void updateXY(int &index_x, int &index_y, int &X, int &Y) {
    if (index_x < 0) {
        index_x += X;
    }
    if (index_y < 0) {
        index_y += Y;
    }
    if (index_x >= X) {
        index_x -= X;
    }
    if (index_y >= Y) {
        index_y -= Y;
    }
}

int main() {
    int x, y;
    string handleStr{};
    vector<vector<char>> game{};
    cin >> x >> y;
    int index_x{}, index_y{};
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
    cin >> handleStr;
    for (int i =0;i<game.size();i++) {
        for (int j = 0; j < game[i].size() ; ++j) {
           if(game[i][j] == '*'){
               game[i][j] = '.';
               index_x = i;
               index_y = j;
           }
        }
    }
    int score{};
    for (auto &i : handleStr) {
        if (i == 'W') {
            index_x--;
            updateXY(index_x, index_y, x, y);
            auto target = game[index_x][index_y];
            if (target == '$') {
                score++;
                game[index_x][index_y] = '.';
            }
        }
        if (i == 'S') {
            index_x++;
            updateXY(index_x, index_y, x, y);
            auto target = game[index_x][index_y];
            if (target == '$') {
                score++;
                game[index_x][index_y] = '.';
            }
        }
        if (i == 'D') {
            index_y++;
            updateXY(index_x, index_y, x, y);
            auto target = game[index_x][index_y];
            if (target == '$') {
                score++;
                game[index_x][index_y] = '.';
            }
        }
        if (i == 'A') {
            index_y--;
            updateXY(index_x, index_y, x, y);
            auto target = game[index_x][index_y];
            if (target == '$') {
                score++;
                game[index_x][index_y] = '.';
            }
        }
    }
    cout << score << endl;
    return 0;
}
