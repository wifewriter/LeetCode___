#include <iostream>
#include <vector>
#include <string>
int main(){
    std::string firstStr,secondeStr;
    std::cin >> firstStr;
    std::cin >> secondeStr;
//    kmp secondeStr next数组 。
//    firstStr = "abcabccdh";
//    secondeStr ="abaabca";

    for (int i =0;i<secondeStr.size();i++) {
        firstStr.push_back(firstStr[i]);
    }
    std::vector<int> secondeStrNextArr(secondeStr.size()+1);
    secondeStrNextArr[0] = -1;
    int i = 0,j = -1;
    while (i<secondeStr.size()){
        if(j == -1 or secondeStr[i] == secondeStr[j]){
            ++j;
            ++i;
            secondeStrNextArr[i] = j;
        } else{
            j = secondeStrNextArr[j];
        }
    }

    i=0;
    j=0;
    while (i<firstStr.size() and j < secondeStr.size()){
        if(j == -1 or firstStr[i] == secondeStr[j]){
            i++;
            j++;
        } else{
            j = secondeStrNextArr[j];
        }
    }

    if(j == secondeStr.size()){
        std::cout <<"yes";
    } else{
        std::cout <<"no";
    }

    return 0;
}