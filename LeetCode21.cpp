/**
 * 题目:
 *将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

 

示例 1：


输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
示例 2：

输入：l1 = [], l2 = []
输出：[]
示例 3：

输入：l1 = [], l2 = [0]
输出：[0]
 

提示：

两个链表的节点数目范围是 [0, 50]
-100 <= Node.val <= 100
l1 和 l2 均按 非递减顺序 排列

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include "string"
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 **/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr)
            return list2;
        if(list2 == nullptr)
            return list1;
        ListNode *index_node;
        ListNode *result_index;
        ListNode *result_index_pre;
        ListNode *result = nullptr;
        if(list1->val>list2->val){
            result = list2;
            result_index = list2->next;
            result_index_pre = list2;
            index_node = list1;
        } else{
            result = list1;
            result_index = list1->next;
            result_index_pre = list1;
            index_node = list2;
        }
        while(result_index != nullptr and index_node != nullptr){
            if(result_index->val > index_node->val){
                result_index_pre->next = index_node;
                ListNode *temp = index_node->next;
                index_node->next = result_index;
                index_node = temp;
                result_index_pre = result_index_pre->next;
            } else {
                result_index_pre = result_index;
                result_index = result_index->next;
            }
        }
        if(index_node != nullptr){
            result_index_pre->next = index_node;
        }
        return result;
    }
};

int main(){
    auto *a= new ListNode(1);
    a->next = new ListNode(3);
    a->next->next = new ListNode(4);

    auto *b= new ListNode(1);
    b->next = new ListNode(2);
    b->next->next = new ListNode(4);

    Solution sol;
    ListNode *result = sol.mergeTwoLists(a,b);

    return 0;
}