#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){
    stack<string> ss{};
    string input;
    cin>>input;
    int res{};
    for(int i=0;i<input.size();i++){
        if(input[i] == '<'){
            if(input.substr(i,5) == "<div>"){
                ss.push("<div>");
            } else if (input.substr(i,6) == "</div>"){
                ss.pop();
                res ++;
            }
        }
    }
    cout << res;
    return 0;
}