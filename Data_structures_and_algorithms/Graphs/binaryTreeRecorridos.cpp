#include <iostream>
#include <vector>

using namespace std;

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> last;
        preOrder(root, last);
        return last;
    }
    
    void preOrder(TreeNode* root, vector<int> &last) {
        if (root != NULL) {
            last.push_back(root->val);
            preOrder(root->left, last);
            preOrder(root->right, last);
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> last;
        inOrder(root, last);
        return last;
    }
    
    void inOrder(TreeNode* root, vector<int> &last) {
        if (root != NULL) {
            inOrder(root->left, last);
            last.push_back(root->val);
            inOrder(root->right, last);
        }
    }
};