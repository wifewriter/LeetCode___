//
// Created by Administrator on 2020/3/3.
//
#include <iostream>
#include "string"
using namespace std;

class Solution {  //思维解法借鉴博客主一只猫的旅行。
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        if (p.size() == 1) {
            return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));
        }
        if (p[1] != '*') {
            if (s.empty()) return false;
            return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }
        while (!s.empty() && (s[0] == p[0] || p[0] == '.')) {
            if (isMatch(s, p.substr(2))) return true;
            s = s.substr(1);
        }
        return isMatch(s, p.substr(2));

    }
};

int main(){
    string str = "aab";
    string str2 = "c*a*b";
    Solution A;
    cout << A.isMatch(str,str2)<<endl;
    return 0;
}