class Solution {
public:
    bool dfs(int node, vector<int> adj[], vector<int>& visited, vector<int>& pathVisited){
        visited[node] = 1;
        pathVisited[node] = 1;

        for(auto it : adj[node]){
            if(!visited[it]){
                if(dfs(it, adj, visited, pathVisited)) return true;
            }else if(pathVisited[it]) return true;
        }
        pathVisited[node] = 0;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //we need to check if there is a cycle in the directed graph.
        //at first we need to create the graph

        vector<int> adj[numCourses];
        vector<int> visited(numCourses,0);
        vector<int> pathVisited(numCourses,0);

        //creating the graph
        for(auto it : prerequisites){
            int i = it[0];
            int j = it[1];
            adj[i].push_back(j);
        }

        for(int i = 0; i < numCourses; i++){
            if(!visited[i]){
                if(dfs(i, adj, visited, pathVisited)) return false;
            }
        }
        return true;
    }
};
