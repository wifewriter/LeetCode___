#include <iostream>
#include "string"

using namespace std;

int calNum(string& S,int len1,string &t,int len2){
    int res = 0;
    for(int i =0;i<= len1-len2;){
        int t_i = i;
        int j = 0;
        for (; j < len2; ) {
            if(t[j]== '*' or S[i] == t[j]) {
                i++;
                j++;
            }
            else{
                break;
            }
        }
        if(j == len2){
            res++;
        }
        i = ++t_i;
    }
    return res;
}

int main(){

    int len1=0,len2=0;
    string S,s;
    std::cin>> len1 >> len2;
    std::cin>>S >>s;
    cout<<calNum(S,len1,s,len2);
    return 0;
}