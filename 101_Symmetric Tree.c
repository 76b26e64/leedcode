/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 bool is_mirror(struct TreeNode* left, struct TreeNode* right) {
    if(!left && !right){
        return true;
    }else if((!left && right) || (left && !right)){
        return false;
    }else if(left->val != right->val){
        return false;
    }

    return is_mirror(left->left, right->right) &&
           is_mirror(left->right,right->left);
}


bool isSymmetric(struct TreeNode* root) {
    if(!root) {
        return false;
    }

    return is_mirror(root->left, root->right);
}
