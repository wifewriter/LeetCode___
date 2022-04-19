//
// Created by Administrator on 2020/3/1.
//
#include <stdio.h>
int reverse();
int main(){
    int x = 1563847412;
    printf_s("%d",reverse(x));
    return 0;
}
int reverse(int x){
    int min[10] = {2,1,4,7,4,8,3,6,4,8};
    int max[10] = {2,1,4,7,4,8,3,6,4,7};
    int a[32];
    int j =0;
    unsigned int temp =0;
    for(int i = 0;i<32;i++)
        a[i] = '0';
    if(x == -2147483648)  return 0;
    else if(x<0){
        a[j++] = '-';
        x *= -1;
    }
    while(x>0){
        a[j++] = x%10;
        x /= 10;
    }
    if((a[0] == '-'&& j >11)|| j>11) return 0;
    else if(a[0] == '-' && j == 11){
        for(int i =1;i<11;i++){
            if(a[i+1] > min[i]) return 0;
            else if (a[i+1]<min[i]) break;
        }
    }
    if(a[0] != '-' && j>10) return 0;
    else if(a[0] != '-'&& j == 10){
        for(int i=0;i<10;i++)
            if(a[i]>max[i]) return 0;
            else if (a[i]<min[i]) break;
    }



    for(int i = 0;i<j;i++){
        if(a[i] == '-');
        else {
            temp = temp *10 +a[i];
        }
    }
    if(a[0] == '-')temp *= -1;

    return temp;
}