class Solution 
{
//http://46aae4d1e2371e4aa769798941cef698.devproxy.yunshipei.com/u012243115/article/details/43053527
//https://leetcode.com/problems/word-ladder-ii/
public:
    vector<string> tmpPath;//用于构造当前的路径
    vector<vector<string> > result;//保存结果
    
	vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
	    unordered_set<string> curLevel;//当前层次集合
	    unordered_set<string> nextLevel;//下一层集合
	    unordered_set<string> unvisited(dict);//储存还未访问的节点
	    unordered_map<string,unordered_set<string> >graph;//图，反向邻接表
	    
	    if(unvisited.count(start)!=0)   
	        unvisited.erase(start);//不储存start，不然待会儿第一层只会不断的死循环
	    
	    curLevel.insert(start);//第一层就start
	    
	    while(unvisited.size()>0&&curLevel.count(end)==0){
	        //循环进行的条件是unvisited中还有字符，或者这一层没有end
	      
	        for(auto iter=curLevel.begin();iter!=curLevel.end();iter++){
	            string curWord=*iter;
	            for(int i=0;i<curWord.size();i++){
	                for(char c='a';c<'z';c++){
	                    string tmp=curWord;
	                    if(tmp[i]==c)   continue;
	                    
	                    tmp[i]=c;
	                    //如果找得到，就说明一下子能够变成某个字符，在途中构造反向图
	                    if(unvisited.count(tmp)>0){
	                        nextLevel.insert(tmp);
	                        graph[tmp].insert(curWord);
	                    }
	                }
	            }
	        }

	        if(nextLevel.empty())   break;
	        //把层次遍历完，把下一层的元素删除
	        for(auto iter=nextLevel.begin();iter!=nextLevel.end();iter++){
	            unvisited.erase(*iter);
	        }
	        
	        curLevel=nextLevel;
	        nextLevel.clear();
	    }
	    //如果当前层次上存在end，说明找到路径，则使用dfs从下到上构造路径。
	    if(curLevel.count(end)>0){
	        DFS_GenPath(graph,end,start);
	    }
	    return result;
	}
	
	void DFS_GenPath(unordered_map<string,unordered_set<string> >&graph,string start,string end){
	    tmpPath.push_back(start);
	    if(start==end){
	        vector<string> tmp=tmpPath;
	        reverse(tmp.begin(),tmp.end());
	        result.push_back(tmp);
	        return;
	    }
	    
	    for(auto iter=graph[start].begin();iter!=graph[start].end();iter++){
	        DFS_GenPath(graph,*iter,end);
	        tmpPath.pop_back();//标准的回溯，上一句是进去，这一句是出来。
	    }
	}
	
	
};
