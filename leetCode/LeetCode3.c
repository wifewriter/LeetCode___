//
// Created by Administrator on 2020/3/2.
//
int lengthOfLongestSubstring(char * s){
    int s_Length = strlen(s);
    int pre =0 ,q =0;//q是末尾 pre 是首位。
    int Num_Temp =0;//暂时存放最长子串长度
    int temp;
    int Num_S = Num_Temp ;
    int j=1;
    // int tmparr[128] = {0};
    while(pre<s_Length && (pre+Num_S)<s_Length){
        // for(int i=0;i<128;i++)tmparr[i] =0;
        int tmparr[128] ={0};
        j=1;
        q=pre;
        if(s[q] !='\0'){
            // arr1 = 's[q++]'-'A';
            tmparr[s[q++]] = j++;
            for(;tmparr[s[q]] == 0 && s[q] != '\0' ;q++)
                tmparr[s[q]] = j++;
            if((Num_Temp=q-pre)>Num_S)
                Num_S = Num_Temp;
        }
        if(s[q]!='\0')pre += tmparr[s[q]];
    }
    return Num_S;
}
