class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        //we need to at first create the graph and then detect if there is a valid topo Sort if there is then that's the ans
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> inDegree;

        //at first we need to find the unique characters
        for(string word : words){
            for(char ch : word){
                inDegree[ch] = 0;
            }
        }

        for(int i = 1; i < words.size(); i++){
            int minLen = min(words[i].size(), words[i-1].size());
            bool flag = false;
            for(int j = 0; j < minLen; j++){
                //first mismatch
                char prev = words[i-1][j];
                char post = words[i][j];
                if(prev != post){
                    //edge does not exist
                    if(adj[prev].find(post) == adj[prev].end()){
                        adj[words[i-1][j]].insert(words[i][j]);
                        inDegree[words[i][j]]++;
                    }
                    flag = true;
                    break;
                }
            }
            if(!flag && words[i-1].size() > words[i].size()){
                return "";
            }
        }

        //now we need to find out the topological sort
        string topoSort = "";
        queue<int> q;
        //finding out whose indegree are 0
        for(auto pair : inDegree){
            char ch = pair.first;
            int degree = pair.second;

            if(degree == 0) q.push(ch);
        }

        while(!q.empty()){
            char node =  q.front();
            q.pop();
            topoSort += node;

            for(auto neighbor : adj[node]){
                inDegree[neighbor]--;
                if(inDegree[neighbor] == 0) q.push(neighbor);
            }
        }

        if(topoSort.size() != inDegree.size()) return "";
        return topoSort;

        
    }
};
