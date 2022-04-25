//
// Created by Administrator on 2020/3/2.
//
char * longestPalindrome(char * s){
    int s_Long = strlen(s);
    int pre =0 , sub  =0;//pre 为开始下标，sub为结束下标。
    int palind_Long = s_Long;
    int Flag = 0,Flag_1;//flag_1为重置palind_Long标志。
    int i = 0,j = 0;
    static char arr[1002] = {0};
    while(!Flag){
        Flag_1 = 0;
        i = pre;
        j = pre+palind_Long -1;
        while(i<j&&s[i] == s[j]){
            i++;
            j--;
        }if(i>=j){
            Flag = 1;
        }
        else if(pre+palind_Long>=s_Long){
            pre = 0;
            palind_Long--;
            Flag_1 = 1;
        }if(!Flag&&!Flag_1){
            pre++;
        }
    }
    for(i=pre,j = 0;i<pre+palind_Long;i++,j++){
        arr[j] = s[i];
    }
    arr[palind_Long] = '\0';
    return arr;
}
