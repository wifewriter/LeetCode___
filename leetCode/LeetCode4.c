//
// Created by Administrator on 2020/3/2.
//
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int Flag = 0,Flag_0 = 0;
    int* s1,num1;
    int* s2,num2;
    if(nums1Size>nums2Size){//s1为长数组，s2为短数组；
        s1 = nums1;
        num1 = nums1Size;
        s2 = nums2;
        num2 = nums2Size;
    }
    else{
        s1 = nums2;
        num1= nums2Size;
        s2 = nums1;
        num2 = nums1Size;
    }
    if(!num1){
        if(num2%2 == 0) return (s2[num2/2]+s2[num2/2-1])/2.0;
        else return s2[num2/2]/1.0;
    }
    if(!num2){
        if(num1%2 == 0) return (s1[num1/2]+s1[num1/2-1])/2.0;
        else return s1[num1/2]/1.0;
    }
    int i=0,j=0;
    int num_Long = num1+num2;
    double max_Temp,min_Temp;
    if(s1[(num_Long+1)/2-1]<=s2[0]){ //j = (num_Long+1)/2,i = 0;
        if((num_Long+1)/2<num1){
            if(num_Long%2 ==0){
                if(s2[0]>=s1[(num_Long+1)/2])min_Temp = s1[(num_Long+1)/2];
                else min_Temp = s2[0];
                max_Temp = s1[(num_Long+1)/2-1];
                Flag_0 =1;
            }else if(num_Long%2 ==1)return (double)s1[(num_Long+1)/2-1];
        }else {//(num_Long+1)/2 == num1.
            if(num_Long%2 ==0){
                min_Temp = s1[(num_Long+1)/2-1];
                max_Temp = s2[0];
                Flag_0 =1;
            }else if(num_Long%2 ==1)return (double)s1[(num_Long+1)/2-1];
        }
    }
    while(!Flag&&!Flag_0){
        i++;
        if(i<num2&&s1[(num_Long+1)/2-i-1]<=s2[i]&&s2[i-1]<=s1[(num_Long+1)/2-i]) Flag = 1;
        if(i == num2)Flag =1;
    }
    j = (num_Long+1)/2-i;
    if(i<num2&&Flag){
        if(num_Long%2 ==1){
            if(s2[i-1]>s1[j-1]) return (double)s2[i-1];
            else return (double)s1[j-1];
        }else if(num_Long%2 == 0){
            if(s2[i-1]>s1[j-1])max_Temp = s2[i-1];
            else max_Temp = s1[j-1];
            if(s2[i]>s1[j])min_Temp = s1[j];
            else min_Temp = s2[i];
        }
    }
    if(i == num2&&Flag){
        if(num_Long%2 == 1){
            if(s2[i-1]>s1[j-1]) return (double)s2[i-1];
            else return (double)s1[j-1];
        }else if(num_Long%2 == 0){
            if((num_Long+1)/2>num2){
                if(s1[j-1]>s2[i-1])max_Temp = s1[j-1];
                else max_Temp = s2[i-1];
                min_Temp = s1[j];
            }else{
                max_Temp = s2[i-1];
                min_Temp = s1[j];
            }
        }
    }
    return ((double)max_Temp+(double)min_Temp)/2.0;
}
