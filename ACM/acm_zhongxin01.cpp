/**
 * 题目:
 *
 */
#include <iostream>
#include "string"
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int handle4class(int clc,int x,int y){
    /**
     * 0:a+b
     * 1:a-b
     * 2:a*b
     * 3:a/b
     */
    if(clc == 0)return x+y;
    else if (clc == 1)return abs(x-y);
    else if(clc == 2) return x*y;
    else if(clc == 3){
        if(x > y and y != 0 ) return x/y;
        else if(x <= y and x !=0 )return y/x;
    }
    return 0;
}

bool judege24(vector<int> arr){
    if(arr.size() == 1) {
        return arr[0] == 24;
    }
    for (int i = 0; i < arr.size()-1; ++i) {
        for (int j = i+1; j < arr.size() ; ++j) {
            vector<int> temp;
            for (int k = 0; k < arr.size(); ++k) {
                if(k != i and k!=j){
                    temp.push_back(arr[k]);
                } else{
                    continue;
                }
            }
            for (int l = 0; l <4; ++l) {
                temp.push_back(handle4class(l,arr[i],arr[j]));
                if(judege24(temp)){
                    return true;
                }
                temp.pop_back();
            }

        }
    }
    return false;
}

bool damage(vector<int> &power){
    return judege24(power);
}

int main() {
    vector<int> a{1,3,4,6};
    cout << damage(a);
    return 0;
}