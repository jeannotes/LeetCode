class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> u_set(wordList.begin(), wordList.end());
        int res = ladderLengthHelper(beginWord, endWord, u_set);
        return res;
    }

    int ladderLengthHelper(string start, string end, unordered_set<string> &dict) {
        if (dict.find(end) == dict.end()) return 0;
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
