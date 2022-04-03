/*
Runtime: 28 ms, faster than 87.90% of C++ online submissions for Binary Search Tree Iterator.
Memory Usage: 24.3 MB, less than 10.62% of C++ online submissions for Binary Search Tree Iterator.
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    std::vector<int> val;
    int pos;
    
    void inOrderTraverse(TreeNode* node) {
        if(!node) return;
        inOrderTraverse(node->left);
        val.push_back(node->val);
        inOrderTraverse(node->right);
    }
    
    BSTIterator(TreeNode* root) {
        inOrderTraverse(root);
        pos = 0;
    }
    
    int next() {
        return val[pos++];
    }
    
    bool hasNext() {
        return pos < val.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
