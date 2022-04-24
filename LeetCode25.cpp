/**
 * 题目:
 *给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。

k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

 

示例 1：


输入：head = [1,2,3,4,5], k = 2
输出：[2,1,4,3,5]
示例 2：



输入：head = [1,2,3,4,5], k = 3
输出：[3,2,1,4,5]
 

提示：
链表中的节点数目为 n
1 <= k <= n <= 5000
0 <= Node.val <= 1000
 

进阶：你可以设计一个只用 O(1) 额外内存空间的算法解决此问题吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-nodes-in-k-group
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
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> list{};
        auto index = head;
        auto pre = 0,Tk = k;
        while (index!= nullptr){
            list.push_back(index);
            index = index->next;
        }
        if(list.size() <= 1 or k == 1)
            return head;
        ListNode* indexTemp{};
        while (Tk <= list.size()){
            auto T = Tk;
            if( T == k){
                head = list[T-1];
                indexTemp = head;
                T--;
                while (T > pre){
                    indexTemp->next = list[T-1];
                    indexTemp = indexTemp->next;
                    T--;
                }
                Tk +=k;
                pre+=k;
            } else{
                while (T > pre){
                    indexTemp->next = list[T-1];
                    indexTemp = indexTemp->next;
                    T--;
                }
                Tk +=k;
                pre+=k;
            }
        }
        if(pre < list.size()){
            indexTemp->next = list[pre];
        } else{
            indexTemp->next = nullptr;
        }
        return head;
    }
};

int main(){
    auto *a= new ListNode(1);
    a->next = new ListNode(2);
//    a->next->next = new ListNode(3);
//    a->next->next->next = new ListNode(4);
//    a->next->next->next->next = new ListNode(5);

    int c = 2;
    Solution sol;
    auto dd = sol.reverseKGroup(a,c);
    return 0;
}