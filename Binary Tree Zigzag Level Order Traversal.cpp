/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> >res;
        if(root==NULL)  return res;
        queue<TreeNode*>q;
        q.push(root);
        bool flag=false;
        while(!q.empty()){
            int n=q.size();
            vector<int> tem;
            
            for(int i=0;i<n;i++){
                TreeNode *tmp=q.front();
                
                tem.push_back(q.front()->val);
                q.pop();
                if(tmp->left)   q.push(tmp->left);
                if(tmp->right)  q.push(tmp->right);
            }
            if(flag)    
                reverse(tem.begin(),tem.end());
            flag=!flag;
            res.push_back(tem);
            
        }
        
        return res;      
    }
};
