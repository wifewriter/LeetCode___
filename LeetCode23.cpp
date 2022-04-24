/**
 * 题目:
 *给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。

 

示例 1：

输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6
示例 2：

输入：lists = []
输出：[]
示例 3：

输入：lists = [[]]
输出：[]
 

提示：

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] 按 升序 排列
lists[i].length 的总和不超过 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-k-sorted-lists
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
private:
    ListNode* merge(ListNode* target,ListNode* list){
        if(target== nullptr)
            return list;
        if(list == nullptr)
            return target;
        decltype(target) head = new ListNode();
        decltype(target) index = head;
        while (target != nullptr and list != nullptr){
            if(target->val <=list->val){
                index->next = target;
                target = target->next;
                index = index->next;
            } else{
                index->next = list;
                list = list->next;
                index = index->next;
            }
        }
        if(target == nullptr){
            index->next = list;
        }
        if(list == nullptr){
            index->next = target;
        }
        index = head->next;
        delete( head);
        return index;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = nullptr;
        if(lists.empty()) return nullptr;
        if(lists.size() == 1) return lists[0];
        head = lists[0];
        for (int i = 1; i < lists.size(); ++i) {
            head = merge(head,lists[i]);
        }
        return head;
    }
};

int main(){

    Solution sol;
    cout<<sol
    return 0;
}