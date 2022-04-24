
#include <iostream>
#include <cstdbool>
int main() {
    int input = 0;
    std::cin>>input;

    if (input == 0 or input == 1) {
        std::cout<<"yes";
        return 0;
    }
    for(auto i  = input/2;i<input;i++){
        if(input % i == 0) {
            std::cout<<"no";
            return 0;
        };
    }
    std::cout <<"yes";
}
