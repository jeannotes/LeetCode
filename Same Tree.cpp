class Solution1 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p==NULL&&q==NULL)
			return true;
		else if( (p==NULL&&q!=NULL)||(p!=NULL&&q==NULL) )
			return false;
		else
		{
			if (p->val==q->val)
			{
				return true;
			}

			else
			{
				return isSameTree(p->LeftNode,q->LeftNode)&&isSameTree(p->RightNode,q->RightNode);
			}
		}
    }
};



