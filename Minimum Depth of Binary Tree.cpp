 //https://leetcode.com/problems/minimum-depth-of-binary-tree/
class Solution1 {
public:
    int minDepth(TreeNode* root) {
    	if (root == NULL)
    		return 0;
    	if (root->left == NULL)
    		return 1+minDepth(root->right);
    	if (root->right == NULL)
    		return 1+minDepth(root->left);
    	int i = minDepth(root->left), j = minDepth(root->right);
    	return 1 + min(i, j);
    }
};
//本题要注意的是，不能写成左子树空，就返回0，这时候就要加1，早返回右边的数值，详见代码
//这里很重要
// 还是不会啊
// 本题不能掉以轻心，要记住上面的总结
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
//不会啊,就用第一个方法啊，加油
//细枝末节的错误啊
// 递归容易出错啊。
