#include <iostream>
#include <string>
#include <vector>
using namespace std;

class A{
public:
    A(){
        cout<<"A constructor"<<endl;
    };
    ~A(){
        cout <<"A destructor"<<endl;
    };
};

void print(){
    cout<<"123";
}

int main(){
    char *a ;
    float *b;
    auto c = &print;
    cout<<sizeof a<<" " << sizeof b << " " <<sizeof c<<endl;
    return 0;
}