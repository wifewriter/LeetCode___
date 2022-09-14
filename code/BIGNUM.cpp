#include <iostream>
#include <string>
#include <utility>
#include <array>
using namespace std;

struct  BIGNUM{
    array<uint32_t,4> m_num;
    BIGNUM(){};
    explicit BIGNUM(array<uint32_t,4> &num):m_num(num){

    };
    BIGNUM operator+(BIGNUM  const &b) const{
        BIGNUM res;
        int flag = false;
        for(int i =0;i<b.m_num.size();i++){
            auto temp = m_num[i]+b.m_num[i];
            if(flag){
                temp +=1;
                flag = false;
            }
            if(m_num[i]/2+b.m_num[i]/2 > INT32_MAX/2){
                flag = true;
            }
            res.m_num[i] = temp;
        }
        return  res;
    };


};
int main(){
    array<uint32_t,4> A{1,2,3,4};
    array<uint32_t,4> B{4,5,6,7};
    BIGNUM a(A);
    BIGNUM b(B);
    auto c = a+b;
    for (auto &a:c.m_num){
        cout << a <<endl;
    }
    return 0;
}