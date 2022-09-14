//
// Created by Administrator on 2022/7/21.
//
#include <algorithm>
#include "iostream"
#include "vector"
using namespace std;
class Solution {
private:
    vector<int> array;
    /*i下标*/
    int m_numSquares(int n,int index){
        if(n == array[index]){
            return 1;
        } else if (index == 1){
            return n;
        } else{
            int n_t = n-array[index-1];
            auto index_t = find_if(array.begin(),array.begin()+index,[&](int &a){
                return a>=n_t;
            }) - array.begin();
            return 1 + m_numSquares(n_t,index_t);
        }
    }
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型
     * @return int整型
     */
    int numSquares(int n) {
        // write code here
        for(int i=1,j=1;j<=10000;i++,j= i*i){
            array.emplace_back(j);
        }
        auto maxOne = find_if(array.begin(),array.end(),[&](int& x){
            return x>=n;
        });
        int index = maxOne-array.begin();
        auto res =n;
        if(array[index] == n){
            res = 1;
        }else{
            for (int i = index; i >= (index)/2 ; --i) {
                auto res_t =m_numSquares(n,i);
                res = min(res,res_t);
            }
        }
        return res;
    }
};


int main(){
    int a = 12;
    Solution sss;
    cout<<sss.numSquares(a);
}
