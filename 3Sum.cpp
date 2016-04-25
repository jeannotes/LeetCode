vector<vector<int>> res;
    vector<vector<int>> threeSum(vector<int>& nums) {
    	if (nums.size()<3)
    		return res;
    	int len=nums.size();sort(nums.begin(),nums.end());
    	for (int i=0;i<len;i++){
    		if (i>0&&nums[i]==nums[i-1])
    			continue;
    		int left=i+1,right=len-1;
    		
    		while(left<right){// 注意这里不能写等于号，不然会导致相同的数字。
    		    int sum=nums[i]+nums[left]+nums[right];
    		    if (sum==0){
        			vector<int>tem1;tem1.push_back(nums[i]);
        			tem1.push_back(nums[left]);tem1.push_back(nums[right]);
        			res.push_back(tem1);
        
        			left++;right--;
        			while (nums[left]==nums[left-1])
        				left++;
        			while (nums[right]==nums[right+1])
        				right--;
        		}else if (sum>0)
        			right--;
        		else
        			left++;
    		}
    
    	}
    	return res;
    }          
 
// 这才是好题目啊,可惜不会啊,第二天早晨做，一次通过
//  这个分支 if(sum==curSum)  里面没 往右往左走,在里面定义vector<int> tem; 不然需要清空的
// 今天终于一次acc，还是有问题啊
// 竟然能够把 int sum=nums[i]+nums[left]+nums[right];  这句话放在外面
//还是没有能够一次通过
