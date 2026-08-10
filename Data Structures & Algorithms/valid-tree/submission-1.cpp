class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
        if(vis[node]) return;

        vis[node] = 1;

        for(auto neighbor : adj[node]){
            if(!vis[neighbor])
                dfs(neighbor, adj, vis);
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        //first we need to check the no of edges
        if(edges.size() != n-1) return false;

        //we need to check if there is a valid path between every node 
        vector<int> visited(n,0);

        //build the adjacency list
        vector<vector<int>> adj(n);

        for(auto it : edges){
            int i =it[0];
            int j = it[1];
            adj[i].push_back(j);
            adj[j].push_back(i);
        }

        dfs(0, adj, visited);
        int cnt = 0;
        //we need to check how many nodes are visited
        for(int i = 0; i < n; i++){
            if(visited[i] == 1) cnt++;
        }
        if(cnt == n) return true;
        return false;
    }
};
