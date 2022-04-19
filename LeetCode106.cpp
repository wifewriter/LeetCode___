/**
 * 题目:
 *给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。

 

示例 1:


输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
输出：[3,9,20,null,null,15,7]
示例 2:

输入：inorder = [-1], postorder = [-1]
输出：[-1]
 

提示:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder 和 postorder 都由 不同 的值组成
postorder 中每一个值都在 inorder 中
inorder 保证是树的中序遍历
postorder 保证是树的后序遍历

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include "string"
#include <vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int post_len = postorder.size();
        int in_len = inorder.size();
        TreeNode *root = CurBuildTree(inorder,0,in_len,postorder,0,post_len);
    };
    TreeNode* CurBuildTree(vector<int>&inorder,int in_begin,int in_end,vector<int>& postorder,int post_begin,int post_end){

        if(post_begin >= post_end)
            return nullptr;
        int root_val = postorder[post_end-1];
        TreeNode *root = new TreeNode(root_val);
        int in_index = in_begin;
        for (; in_index <in_end ; ++in_index) {
            if(inorder[in_index] == root_val) break;
        }
        if(in_index == in_end){ return root;}
        root->left = CurBuildTree(inorder,in_begin,in_index,postorder,post_begin,post_begin+in_index-in_begin);
        root->right = CurBuildTree(inorder,in_index+1,in_end,postorder,post_begin+in_index-in_begin,post_end-1);
        return root;
    }
};

int main(){
    Solution sol;
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    TreeNode *t= sol.buildTree(inorder,postorder);
    return 0;
}