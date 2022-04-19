//
// Created by Administrator on 2020/3/6.
//
#include <iostream>
#include "string"
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1){
            return *strs.begin();
        }
        if(strs.empty()){
            return "";
        }
        string str{};
        string str_t{};
        int index = 0;
        int len = (*strs.begin()).size();
        bool flag = false;
        for(auto &t :strs){
            int len_t = t.size();
            len = len_t < len?len_t:len;
        }
        for (; index <len ; ++index) {
            for (auto i = strs.begin();i != strs.end() ;i++) {
                if ((*i).size() >= index) {
                    if (i == strs.begin()) {
                        str_t.push_back((*i)[index]);
                    } else if (str_t[index] == (*i)[index]) {
                        continue;
                    } else {
                        flag = true;
                        break;
                    }
                }
            }
            if(flag) break;
        }
        if(index == 0)
            return "";
        else if(index == len){
            return str_t;
        } else{
            str.assign(str_t.begin(), str_t.begin() + index);
            return str;
        }
    }
};
int main(){
    vector<string> strs = {"flower","flow","flight"};
    Solution a;
    cout<<a.longestCommonPrefix(strs);

    return 0;
}