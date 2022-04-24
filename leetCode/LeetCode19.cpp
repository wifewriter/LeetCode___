/**
 * 题目:
 *给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

 

示例 1：


输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
示例 2：

输入：head = [1], n = 1
输出：[]
示例 3：

输入：head = [1,2], n = 1
输出：[1]
 

提示：

链表中结点的数目为 sz
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 

进阶：你能尝试使用一趟扫描实现吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int size{};
        auto index = head;
        while (index != nullptr){
            size++;
            index = index->next;
        }
        int num = size - n;
        if(num == 0 ){
            if(size == 1){
                return nullptr;
            } else{
                return head->next;
            }
        }
        auto tt = 1;
        index = head;
        while (tt++ < num){
            index = index->next;
        }
        auto Temp = index->next;
        index->next = Temp->next;
        return head;
    }
};

int main(){
    ListNode e(5);
    ListNode d(4,&e);
    ListNode c(3,&d);
    ListNode b(2,&c);
    ListNode a(1,&b);
    int n = 2;
    Solution sol;
    auto kk = sol.removeNthFromEnd(&a,n);
    return 0;
}