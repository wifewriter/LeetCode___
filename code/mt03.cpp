#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;
int lastres =0;
//36%
int plan(string &s,vector<string> &t){
    if(t.size() <=1 ) return t[0] == s;
    else{
        string s1 = t.back();
        t.pop_back();
        string s2 = t.back();
        t.pop_back();
        string res1 = s1+s2;
        t.emplace_back(res1);
        lastres += plan(s,t);
        if (s1 != s2) {
            t.pop_back();
            string res2 = s2 + s1;
            t.emplace_back(res2);
            lastres += plan(s, t);
        }
    }
    return lastres;
}

int main(){

    int len1=0,len2=0;
    std::cin>> len1 >> len2;
    string S;
    cin>>S;
    vector<int> t_len{};
    vector<string> t_str;
    int id2 = len2;
    while (id2-- > 0){
        int temp;
        cin >> temp;

        t_len.emplace_back(temp);
    }
    int id3 = len2;
    while (id3-->0){
        string s;
        cin>>s;
        auto pindex = std::find(t_str.begin(), t_str.end(), s);
        if( pindex != t_str.end()){
            *pindex += s;
        } else{
            t_str.emplace_back(s);
        }
    }

    cout << plan(S,t_str);
    return 0;
}