/**
 * 题目:
 *
 */
#include <iostream>
#include "string"
#include <vector>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        //把next数组理解成最大公共前缀长度容易理解一些。算法如下
        vector<int> nextArr(needle.size()+1);
        nextArr[0] = -1;
        int i = -1;
        for (int j = 0; j <needle.size() ; ) {
            if(i == -1 or needle[j] == needle[i]){
                j++;
                i++;
                nextArr[j] = i;
            } else{
                i = nextArr[i];
            }
        }

        int k = 0;
        int l = 0;
        while (k == -1 or (l < haystack.size() and k < needle.size())){
            if(k == -1 or haystack[l] == needle[k]){
                l++;
                k++;
            } else{
                k = nextArr[k];
            }
        }
        if(k == needle.size()){
            return l-k;
        } else{
            return -1;
        }
    }
};

int main(){
    string haykey = "hello";
    string needle = "ll";
    Solution sol;
    cout<< sol.strStr(haykey,needle);
    return 0;
}