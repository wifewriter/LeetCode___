#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    vector<int> a{1,2,3,4,5,6,6,7,8,9,10};
    for (auto i = a.begin();  i!=a.end() ;) {
        if(*i == 6){
           i =  a.erase(i);
        } else{
            i++;
        }
    }
    for (auto &i:a) {
        cout<<i<<" "<<endl;
    }
    return 0;
}