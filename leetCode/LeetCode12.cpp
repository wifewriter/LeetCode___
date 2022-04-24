//
// Created by Administrator on 2020/3/6.
//
#include <iostream>
#include "string"
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    unordered_map<int ,string> numToString{
        pair<int ,string>(1,"I"),
        pair<int ,string>(4,"IV"),
        pair<int ,string>(5,"V"),
        pair<int ,string>(9,"IX"),
        pair<int ,string>(10,"X"),
        pair<int ,string>(40,"XL"),
        pair<int ,string>(50,"L"),
        pair<int ,string>(90,"XC"),
        pair<int ,string>(100,"C"),
        pair<int ,string>(400,"CD"),
        pair<int ,string>(500,"D"),
        pair<int ,string>(900,"CM"),
        pair<int ,string>(1000,"M"),
    };
public:
    string intToRoman(int num) {
        string str{};
        vector<int> result{};
        while(num > 0){
            result.push_back(num%10);
            num /= 10;
        }
        auto endIndex = result.end()-1; //end - > begin
        while (endIndex - result.begin() >= 0){
            int exp = endIndex - result.begin();
            if(exp == 3){
                //千
                auto num_t = *endIndex;
                while (num_t > 0){
                    str += numToString[1000];
                    num_t--;
                }
            } else {

                if (*endIndex == 4 or *endIndex == 9) {
                    auto times = (*endIndex) * pow(10, exp);
                    str += numToString[times];
                } else {
                    int num_t = *endIndex;
                    if (num_t >= 5) {
                        str += numToString[5 * pow(10, exp)];
                        num_t -= 5;
                    }
                    while (num_t > 0) {
                        str += numToString[1 * pow(10, exp)];
                        num_t--;
                    }
                }
            }

            endIndex--;
        }
        return str;
    }
};

int main(){
    int num = 101;
    Solution a;
    cout<<a.intToRoman(num);

    return 0;
}