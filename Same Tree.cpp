//递归写法
class Solution1 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p==NULL&&q==NULL)
			return true;
		else if( (p==NULL&&q!=NULL)||(p!=NULL&&q==NULL) )
			return false;
		else
		{
			if (p->val!=q->val)
			{
				return false;
			}

			else
			{
				return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
			}
		}
    }
};

//迭代写法
class Solution
{
public:
	bool isSameTree(TreeNode *p,TreeNode *q){
		stack<TreeNode* > s;
		s.push(p);
		s.push(q);

		while (!s.empty())//true--空  false--不空
		{
			p=s.top();s.pop();
			q=s.top();s.pop();

			if(p==NULL&&q==NULL)
				continue;
			if( (p!=NULL&&q==NULL)||(p==NULL&&q!=NULL) )
				return false;
			if(p->val!=q->val)
				return false;
			
			s.push(p->left);
			s.push(q->left);

			s.push(p->right);
			s.push(q->right);	
		}
		return true;
	}
};
//写迭代的时候其实是有阻拦的，现在让我说迭代和递归的区别有如下：
//迭代主循环有continue和false，递归不一样。更多的是两者思维方式不同


