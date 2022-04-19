//
// Created by Administrator on 2020/3/6.
//
#include <iostream>
#include "string"
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<string ,int> stringToNum{
            pair<string ,int>("I" ,1),
            pair<string ,int>("IV",4),
            pair<string ,int>("V" ,5),
            pair<string ,int>("IX",9),
            pair<string ,int>("X" ,10),
            pair<string ,int>("XL",40),
            pair<string ,int>("L" ,50),
            pair<string ,int>("XC",90),
            pair<string ,int>("C" ,100),
            pair<string ,int>("CD",400) ,
            pair<string ,int>("D" ,500),
            pair<string ,int>("CM",900),
            pair<string ,int>("M" ,1000),
    };
public:
    int romanToInt(string s) {
        if(s.empty())
            return 0;
        if(s.size() == 1)return stringToNum[s];
        string str_t{s.begin(),s.begin()+2};
        if(stringToNum[str_t]){
            string string1(s.begin()+2,s.end());
            return stringToNum[str_t] + romanToInt(string1);
        } else{
            string string1(s.begin()+1, s.end());
            string str_begin(s.begin(),s.begin()+1);
            return stringToNum[str_begin] + romanToInt(string1) ;
        }
    }
};

int main(){
    string b = "III";
    Solution a;
    cout<<a.romanToInt(b);

    return 0;
}