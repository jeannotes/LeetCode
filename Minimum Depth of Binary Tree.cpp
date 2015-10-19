/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //https://leetcode.com/problems/minimum-depth-of-binary-tree/
class Solution1 {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL&&root->right==NULL){
            return 1;
        }
        
        int left=INT_MAX;
        if(root->left){
            left=minDepth(root->left)+1;
        }
        
        int right=INT_MAX;
        if(root->right){
            right=minDepth(root->right)+1;
        }
        return min(left,right);
        //如果直接写 return min(minDepth(root->left)+1,minDepth(root->right)+1)这句的话
        //实际上忽略了根节点，一定是从根节点到叶子的最短距离
        
    }
};


class Solution2 {
public:
    int minDepth(TreeNode* root) {
        return BFS(root);
    }
    
    int BFS(TreeNode * root){
        if(root==NULL){
            return 0;
        }
        queue<pair<TreeNode*,int> >q;
        q.push(make_pair(root,1));
        while(!q.empty()){
            TreeNode *curNode=q.front().first;
            int curStep=q.front().second;
            q.pop();//这一层结束
            if(curNode->left==NULL&&curNode->right==NULL){
                return curStep;
                //本题的意思就是只要有一层第一个出现空节点就是最小值
            }
            if(curNode->left!=NULL){
                q.push(make_pair(curNode->left,curStep+1));
            }
            if(curNode->right!=NULL){
                q.push(make_pair(curNode->right,curStep+1));
            }
            //本题的巧妙在于我每次都存入一层的节点，当然是没有空的情况下
            //当然题目一开始就判断了，如果下一个节点的左右孩子是空的话，直接返回
        }
    }
    
};
