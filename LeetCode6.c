#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *convert(char*,int);
int main() {
    char *s = "LEETCODEISHIRING", numRows = 4;
    printf_s("%s",convert(s,numRows));
    //system("pause");
    return 0;
}
char * convert(char * s, int numRows){
        int a=0;
        if(s)
             a = strlen(s);
        else return NULL;
        char *A = NULL;
        A = (char*)malloc(sizeof(char)*(a+1));
        int i=0,j =0,k=0;//k:layers,i:s , j:a[]
        int intervalNum = 0 ;
        if (numRows>2){
            intervalNum = 2*numRows -2;
        } else {
            if (numRows<=0)return 0;
            intervalNum = numRows;
        }
        while (k<numRows){
            if(i<a) {
                A[j++] = s[i];
                if (k == 0 || k == (numRows-1)) {
                    i += intervalNum;
                } else {
                    i += intervalNum - 2 * k;
                   if(i<a){
                    A[j++] = s[i];
                   }
                    i += 2 * k;
                }
            } else i = ++k;
        }
        A[a] = '\0';
    return A;
}
