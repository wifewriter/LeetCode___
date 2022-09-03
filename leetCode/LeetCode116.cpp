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
#include <deque>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return nullptr;
        deque<Node*> dq;
        dq.push_back(root);
        do{
            int n = dq.size();
            int i = 0;

            while(i++<n){
                auto datapre = dq.front();
                dq.pop_front();
                auto datanext = dq.front();
                if(i<n){
                    datapre->next = datanext;
                } else{
                    datapre->next = nullptr;
                }
                if(datapre->left != nullptr) dq.push_back(datapre->left);
                if(datapre->right != nullptr) dq.push_back(datapre->right);
            }
        }while(!dq.empty());
        return root;
    }
};

int main(){

    Solution sol;
    cout<<sol
    return 0;
}