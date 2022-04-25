//
// Created by yy on 22-4-24.
//
#include <vector>
#include <iostream>

using namespace std;
int main() {
    int x, y;
    vector <vector<char>> matrix{};
    cin >> x >> y;
    auto t_x = x;
    while (t_x--) {
        vector<char> matrix_t{};
        auto t_y = y;
        while (t_y--) {
            char t{};
            cin >> t;
            matrix_t.push_back(t);
        }
        matrix.push_back(matrix_t);
    }
    //code insert here
}

