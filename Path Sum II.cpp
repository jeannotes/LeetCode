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
            result.push_back(temp);//这个地方不能够加return //0 1 1 sum=1 加上return 返回 01 011
        }
        pathSumHelper(root->left,sum - root->val,temp,result);
        pathSumHelper(root->right,sum - root->val,temp,result);
        
        temp.pop_back();
    }
};
//其实我还是不会
//几号，回溯中间不能有return
