/**
 * 题目:
 *设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。

循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。

你的实现应该支持如下操作：

MyCircularQueue(k): 构造器，设置队列长度为 k 。
Front: 从队首获取元素。如果队列为空，返回 -1 。
Rear: 获取队尾元素。如果队列为空，返回 -1 。
enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
isEmpty(): 检查循环队列是否为空。
isFull(): 检查循环队列是否已满。
 

示例：

MyCircularQueue circularQueue = new MyCircularQueue(3); // 设置长度为 3
circularQueue.enQueue(1);  // 返回 true
circularQueue.enQueue(2);  // 返回 true
circularQueue.enQueue(3);  // 返回 true
circularQueue.enQueue(4);  // 返回 false，队列已满
circularQueue.Rear();  // 返回 3
circularQueue.isFull();  // 返回 true
circularQueue.deQueue();  // 返回 true
circularQueue.enQueue(4);  // 返回 true
circularQueue.Rear();  // 返回 4
 

提示：

所有的值都在 0 至 1000 的范围内；
操作数将在 1 至 1000 的范围内；
请不要使用内置的队列库。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-circular-queue
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include "string"
#include <vector>
using namespace std;



class MyCircularQueue {
private:
    struct queueNode{
        struct queueNode* next;
        struct queueNode* pre;
        int value;
    };
    queueNode *Head;
    queueNode *tail;
    int total_num;
    int now_num;
    queueNode * newNode(){
        queueNode *temp = new(queueNode);
        temp->value = 0;
        temp->next = nullptr;
        temp->pre = nullptr;
        return temp;
    };
public:
    MyCircularQueue(int k) {
        if(k<0) return;
        struct queueNode *index_ptr;
        for(auto i = 0;i < k;i++){
            struct queueNode* temp = newNode();
            if(i == 0){
                Head = temp;
                tail = temp;
                index_ptr = temp;
                continue;
            }
            index_ptr->next =temp;
            temp->pre = index_ptr;
            index_ptr = index_ptr->next;
        }
        index_ptr->next = Head;
        Head->pre = index_ptr;
        total_num = k;
        now_num = 0;
    }

    bool enQueue(int value) {
        if(now_num == total_num)
            return false;
        if(now_num == 0 and total_num > 0){
            tail->value = value;
            now_num++;
            return true;
        }
        tail = tail->next;
        tail->value = value;
        now_num++;
        return true;
    }

    bool deQueue() {
        if(now_num == 0) return false;
        if(now_num == 1){
            now_num--;
            return true;
        }
        Head = Head->next;
        now_num--;
        return true;
    }

    int Front() {
        if(now_num == 0) return -1;
        return Head->value;
    }

    int Rear() {
        if(now_num == 0) return -1;
        return tail->value;
    }

    bool isEmpty() {
        if(now_num==0) return true;
        return false;
    }

    bool isFull() {
        if(now_num == total_num) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main(){
//["MyCircularQueue","enQueue","Rear","Rear","deQueue","enQueue","Rear","deQueue","Front","deQueue","deQueue","deQueue"]
//[[6],[6],[],[],[],[5],[],[],[],[],[],[]]
    MyCircularQueue sol(1);
    cout<<sol.enQueue(1)<<endl;
    cout<<sol.enQueue(2)<<endl;
    return 0;
}