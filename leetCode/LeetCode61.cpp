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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return head;
        auto temp = head;
        int size=0;
        while(temp!=nullptr){
            size++;
            temp = temp->next;
        }
        while(k>=size){
            k-=size;
        }
        if(k==0 or k==size) return head;
        auto indexpre= head;
        auto indexnext = head;
        while(indexnext->next != nullptr){
            if(k-->0){
                indexnext = indexnext->next;
            }else{
                indexnext = indexnext->next;
                indexpre = indexpre->next;
            }
        }
        auto headnew = indexpre->next;
        indexpre->next = nullptr;
        indexnext->next = head;
        return headnew;
    }
};
int main(){

    Solution sol;
    cout<<sol
    return 0;
}