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
class Solution {
public:

    vector<int> tem;
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root==NULL) return res;
        pathSumHelper(root, 
                       targetSum);
        return res;
    }
    void pathSumHelper(TreeNode* root, 
                        int targetSum) { 
        if (root==NULL) return ;
        tem.push_back(root->val);
        if (root->left==NULL && root->right==NULL && root->val==targetSum){
            res.push_back(tem);
        }        
        pathSumHelper(root->left, 
                       targetSum-root->val);
        pathSumHelper(root->right, 
                       targetSum-root->val);
        tem.pop_back();
    }
};
//其实我还是不会，中间的return 还是有问题啊
//几号，回溯中间不能有return，的，加油啊
