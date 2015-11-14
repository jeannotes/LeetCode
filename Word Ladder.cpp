class Solution {
public:
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		queue<pair<string,int> >q;
		unordered_set<string> visited;
		
		q.push(make_pair(start,1));
		visited.insert(start);
		
		//开始判断
		
		while(!q.empty()){
		    string curStr=q.front().first;
		    int curStep=q.front().second;
		    q.pop();
		    
		    for(int i=0;i<curStr.size();i++){
		        string tmp=curStr;
		        for(int j=0;j<26;j++){
		            tmp[i] = j+'a';
		            if(tmp==end)    return curStep+1;
		            if(visited.find(tmp)==visited.end()&&dict.find(tmp)!=dict.end()){
		               //为了避免"hot" "dog" ["hot","dog"] 这种情况下，程序不动，一直在运行
		                visited.insert(tmp);
		                q.push(make_pair(tmp,curStep+1));
		            }
		        }
		    }
		}
		return 0;
	}
};
