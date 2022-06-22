//
// Created by yy on 22-4-24.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool checkMatrix(vector<vector<int>>  &matrix){
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size() ; ++j) {
            if(matrix[i][j] ==1){
                if((matrix[i-1][j] + matrix[i+1][j] + matrix[i][j-1]+matrix[i][j+1]) == 3){
                    if(!matrix[i-1][j]){
                        matrix[i-1][j] = 1;
                        return true;
                    } else if(!matrix[i+1][j]){
                        matrix[i+1][j] = 1;
                        return true;
                    } else if(!matrix[i][j-1]){
                        matrix[i][j-1] = 1;
                        return true;
                    } else if(!matrix[i][j+1]){
                        matrix[i][j+1] = 1;
                        return true;
                    }
                }
            }
        }
    }
}

int main() {
    vector<vector<int> > move;
    int x{};
    int maxX{},maxY{};
    cin >> x;
    auto t_x = x;
    while (t_x--){
        vector<int> temp;
        int t{};
        for (int i = 0; i <2 ; ++i) {
            cin >>t;
            if(i == 0){
                maxX = maxX > t? maxX:t;
            } else{
                maxY = maxY > t?maxY:t;
            }
            temp.emplace_back(t);
        }
        move.emplace_back(temp);
    }
    vector<int> result(move.size());
    int size = max(maxX,maxY)+4;
    vector<vector<int >> matrix(size);
    for (int j = 0; j < matrix.size() ; ++j) {
        for (int i = 0; i < size; ++i) {
            matrix[j].push_back(0);
        }
    }
    for (int i = 0; i < move.size() ; ++i) {
        matrix[move[i][0]+1][move[i][1]+1] = 1;
        while (checkMatrix(matrix)){
            result[i] +=1;
        }
    }
    for (auto &i : result) {
        cout <<i << endl;
    }
    //code insert here
}

