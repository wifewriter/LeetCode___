/**
 * 题目:
 *给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

 

示例 1：


输入：head = [1,2,3,4]
输出：[2,1,4,3]
示例 2：

输入：head = []
输出：[]
示例 3：

输入：head = [1]
输出：[1]
 

提示：

链表中节点的数目在范围 [0, 100] 内
0 <= Node.val <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/swap-nodes-in-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include "string"
#include <vector>
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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head) return {};
        auto first = head;
        auto second = head->next;
        bool flag = true;
        while (first != nullptr and second != nullptr){
            if(flag){
                first->next = second->next;
                head = second;
                second->next = first;
                first = head->next;
                second = first->next;
                flag = false;
            } else{
                if(!second->next){
                    break;
                }
                first->next = second->next;
                second -> next = first->next->next;
                first->next->next = second;
                first = second;
                second = second->next;
            }

        }
        return head;

    }
};

int main(){

    Solution sol;
    cout<<sol
    return 0;
}