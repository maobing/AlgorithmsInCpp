struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// All tree algorithms use recursion!
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL) return true;
        else if(root->left != NULL && root->right != NULL) {
          return isBalanced(root->left) && isBalanced(root->right);
        }
        else {
          return false;
        }
    }
};
