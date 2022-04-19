//
// Created by Administrator on 2020/3/3.
//
#include <iostream>
#include "string"
using namespace std;
class Solution {
    const int tag = 11;
    int arr[11]  = {0};

    bool judgeArr(int arr[]){
        int j = 0,i =0;
        for(;arr[j] != tag;j++);
        j--;
        while (i<=j){
            if(arr[i] != arr[j])return false;
            i++;j--;
        }
        return true;
    }
public:
    bool isPalindrome(int x) {
        if(x > 0 ){
            for(int i = 0; x > 0 ; x/=10){
                arr[i++] = x%10;
            }
            return judgeArr(arr);
        }else if(x<0) return false;
            return true;
    }
    Solution(){
        for(int i = 0;i<11;i++)
            arr[i] = tag;
    }
};
int main(){
    Solution judge;
    int x = 101;
    cout << judge.isPalindrome(x) << endl;
}
