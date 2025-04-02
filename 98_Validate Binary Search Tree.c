/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool explorer(struct TreeNode* node, long long min_val, long long max_val) {

    if(!node){
        return true;
    }

    if(node->val <= min_val || max_val <= node->val){
        return false;
    }

    bool left = explorer(node->left, min_val, node->val);
    bool right = explorer(node->right, node->val, max_val);
    return (left && right);
}

bool isValidBST(struct TreeNode* root) {
    if (!root){
        return false;
    }

    return explorer(root, LLONG_MIN, LLONG_MAX);
}