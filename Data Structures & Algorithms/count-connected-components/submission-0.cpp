class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
        vis[node] = 1;

        for(auto neighbor : adj[node]){
            if(!vis[neighbor]) dfs(neighbor, adj, vis);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        //construct the graph
        vector<vector<int>> adj(n);

        vector<int> vis(n,0);

        int count = 0;

        for(auto it : edges){
            int i = it[0];
            int j = it[1];
            adj[i].push_back(j);
            adj[j].push_back(i);
        }

        for(int i = 0; i < n; i++){
            if(!vis[i]) {
                count++;
                dfs(i, adj, vis);
            }
        }
        return count;

    }
};
