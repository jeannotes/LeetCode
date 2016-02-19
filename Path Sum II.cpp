class Solution {
//https://leetcode.com/problems/path-sum-ii/
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> temp;
        vector< vector<int> >result;
        pathSumHelper(root,sum,temp,result);
        return result;
        //好久时间
    }
    
    void pathSumHelper(TreeNode *root,int sum,vector<int> &temp,vector<vector<int> >&result){
        if(root==NULL){
            return;
        }
        temp.push_back(root->val);
        if(root->left==NULL&&root->right==NULL&&root->val==sum){
            result.push_back(temp);
        }
        pathSumHelper(root->left,sum - root->val,temp,result);
        pathSumHelper(root->right,sum - root->val,temp,result);
        
        temp.pop_back();
    }
};
//不会啊
