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

class MyCircularDeque {
private:
    struct Node {
        Node *next;
        Node *pre;
        int val;

        Node() {
            next = nullptr;
            pre = nullptr;
            val = 0;
        };

        Node(int a) : val(a) {
            next = nullptr;
            pre = nullptr;
        };

        Node(Node *p) {
            next = p->next;
            pre = p;
            this->next->pre = this;
            p->next = this;
            val = 0;
        };
    };

    Node *phead;
    int maxSize;
    int count;
public:
    MyCircularDeque(int k) {
        phead = new Node(-1);
        phead->next = phead;
        phead->pre = phead;
        count = 0;
        maxSize = k;
    }

    bool insertFront(int value) {
        if (count >= maxSize) {
            return false;
        }
        auto pNode = new Node(value);
        pNode->next = phead->next;
        pNode->pre = phead;
        phead->next = pNode;
        pNode->next->pre = pNode;
        count++;
        return true;
    }

    bool insertLast(int value) {
        if (count >= maxSize) {
            return false;
        }
        auto pNode = new Node(value);
        pNode->next = phead;
        pNode->pre = phead->pre;
        phead->pre = pNode;
        pNode->pre->next = pNode;
        count++;
        return true;
    }

    bool deleteFront() {
        if (count <= 0) return false;
        auto pNode = phead->next;
        phead->next = pNode->next;
        pNode->next->pre = phead;
        delete pNode;
        count--;
        return true;
    }

    bool deleteLast() {
        if (count <= 0) return false;
        auto pNode = phead->pre;
        pNode->pre->next = phead;
        phead->pre = pNode->pre;
        delete pNode;
        count--;
        return true;
    }

    int getFront() {
        if (count > 0)
            return phead->next->val;
        else return -1;
    }

    int getRear() {
        if (count > 0)
            return phead->pre->val;
        else return -1;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == maxSize;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

int main() {
    int k = 3;
    MyCircularDeque *obj = new MyCircularDeque(k);
    int value = 3;
    bool param = obj->insertLast(1);
    bool param_2 = obj->insertLast(2);
    bool param_1 = obj->insertFront(3);
    bool param1 = obj->insertFront(4);

    bool param_3 = obj->deleteFront();
    bool param_4 = obj->deleteLast();
    int param_5 = obj->getFront();
    int param_6 = obj->getRear();
    bool param_7 = obj->isEmpty();
    bool param_8 = obj->isFull();
    return 0;
}