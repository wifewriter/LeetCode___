//
// Created by Administrator on 2020/3/6.
//
#include <iostream>
#include "string"
#include <stack>
using namespace std;
class MyQueue {
public:
    MyQueue() {

    }
    void changeStack(){
        while (!in_stack.empty()){
            int x = in_stack.top();
            in_stack.pop();
            out_stack.push(x);
        }
    }
    void reverseStack(){
        while (!out_stack.empty()){
            int x = out_stack.top();
            out_stack.pop();
            in_stack.push(x);
        }
    }

    void push(int x) {
        in_stack.push(x);
    }

    int pop() {
        changeStack();
        int result = out_stack.top();
        out_stack.pop();
        reverseStack();
        return result;
    }

    int peek() {
        changeStack();
        int result = out_stack.top();
        reverseStack();
        return result;
    }

    bool empty() {
        return in_stack.empty();
    }

private:
    std::stack<int> in_stack;
    std::stack<int> out_stack;
};

int main(){

//    MyQueue myQueue = new MyQueue();
//    myQueue.push(1); // queue is: [1]
//    myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
//    myQueue.peek(); // return 1
//    myQueue.pop(); // return 1, queue is [2]
//    myQueue.empty(); // return false

    int x =1;
    MyQueue* obj = new MyQueue();
    obj->push(x);
    int param_2 = obj->pop();
    int param_3 = obj->peek();
    bool param_4 = obj->empty();

    return 0;
}