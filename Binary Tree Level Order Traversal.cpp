class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> >res;
        if(root==NULL)  return res;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int n=q.size();
            vector<int>tem;
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                tem.push_back(temp->val);
                if(temp->left)   q.push(temp->left);
                if(temp->right)   q.push(temp->right);
                q.pop();
            }
            res.push_back(tem);
        }
        
        return res;
    }
};
//不能捡了西瓜丢了芝麻
// int n=q.size(); 这句话不能少

class Solution {
public:
    vector<vector<int> > res;

    void DFS(TreeNode* root, int level)
    {
        if (root == NULL) return;
        if (level == res.size()) // The level does not exist in output
        {
            res.push_back(vector<int>()); // Create a new level
        }
    
        res[level].push_back(root->val); // Add the current value to its level
        DFS(root->left, level+1); // Go to the next level
        DFS(root->right,level+1);
    }
    
    vector<vector<int> > levelOrder (TreeNode *root) {
        DFS(root, 0);
        return res;
    }
};
