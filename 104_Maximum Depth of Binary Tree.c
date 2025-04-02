/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if(!root){
        return 0;
    }
    int left_depth = maxDepth(root->left);
    int right_depth = maxDepth(root->right);

    int max_depth;
    if(left_depth > right_depth){
        max_depth = left_depth + 1;
    }else{
        max_depth = right_depth + 1;
    }
    return max_depth;
}