#include <iostream>
#include "string"
using namespace std;
class Solution {
    int i,j =0;
    bool flag = 1,mutex = 1,zeRo = 1; //分别是正负号，正负号赋值互斥，零赋值 三个标记
    string maxstr = "2147483647";   //定义进行比较的最值字符串
    string minstr = "2147483648";
public:
    int myAtoi(string str = NULL) {
        //  if(str) {
        for (i = 0; str[i] == ' '||str[i] == '0'||str[i] == '-'||str[i] =='+'; ++i){//for循环忽略字符串前面的空格，0，+-号
            if(zeRo == 0 &&(str[i]=='+'||str[i]=='-'||str[i] == ' '))return 0;     //但是考虑 0-，-/+ 0空格，空格+-，这些情况要
            if(mutex == 0 && str[i] == ' ') return 0;                               //分别讨论
            if((str[i] =='+'||str[i]=='-') && mutex == 0) return 0;
            if(zeRo == 1 && str[i] == '0') zeRo =0;
            if(str[i] == '+' && mutex == 1)mutex = 0;
            else if(str [i] == '-' && mutex == 1){flag = 0;mutex = 0;}
        }
        j = i;
        while (str[i] != '\0' && str[i]>='0' && str[i]<='9')i++;
        if(j ==i) return 0;
        if( i-j> 10){
            if(flag)return 2147483647;
            else return -2147483648;
        }
        switch (flag){
            case 1:if(i-j ==10)
                    for (int k = 0; k <10 ; ++k) {
                        if(str[j+k] < maxstr[k]) break;
                        else if(str[j+k] == maxstr[k]) continue;
                        else if (str[j + k] > maxstr[k]) return 2147483647;
                    }
                return result(str,j,i);
                break;
            case 0: if(i-j ==10)
                    for (int k = 0; k <10 ; ++k){
                        if(str[j+k] < minstr[k]) break;
                        else if(str[j+k] == minstr[k]) continue;
                        else if(str[j+k] > minstr[k]) return -2147483648;
                    }
                return -1*result(str,j,i);
                break;
        }
        return 0;
    }
    unsigned int result (string str,int i,int j){ //下标从i开始到j-1结束的字符串转换为整数。
        unsigned int temp  =0;
        for (; i <j ; ++i) {
            temp = str[i]-'0'+temp * 10; //这里的加法顺序从左向右加不能更改，写成 temp = temp *10 +str[i] -'0'会int溢出
        }
        return temp;
    }
};
int main() {
    Solution atoi;
    string string2 = "-2147483648";
    cout << atoi.myAtoi(string2) << endl;
    return 0;
}
