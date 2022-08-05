/**
 * 题目:
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <stack>
#include <list>
#include <algorithm>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        auto first = new struct ListNode(-1,head);
        auto res = first;
        auto second = first;
        auto index = first->next;
        while(second == res){
            if(index->val >=x){
                second = index;
            } else{
                first = index;
            }
            index = index->next;
        }
        while(index != nullptr){
            if(index->val < x){
                auto next = first->next;
                first->next = index;
                index = index->next;
                first->next->next = next;
                second->next = index;
            }else{
                second = index;
                index = index->next;
            }
        }
        return res->next;
    }
};

int main(){
//    ListNode a(2, nullptr);
//    ListNode b(5,&a);
//    ListNode c(2,&b);
//    ListNode d(3,&c);
//    ListNode e(4,&d);
//    ListNode f(1,&e);

    ListNode a(1, nullptr);
    ListNode b(2, &a);

    int x = 2;
    Solution sol;
    auto res = sol.partition(&b,x);
    return 0;
}