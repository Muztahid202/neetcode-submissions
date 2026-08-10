class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis){
        vis[node] = 1;

        for(auto neighbor : adj[node]){
            if(vis[neighbor]){
                if(neighbor != parent) return true;
            }
            else if (dfs(neighbor, node, adj, vis)) return true;
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;

        //visited array
        vector<int> vis(n,0);

        //construct the graph
        vector<vector<int>> adj(n);
        for(const auto& it : edges){
            int i = it[0];
            int j = it[1];
            adj[i].push_back(j);
            adj[j].push_back(i);
        }

        //detect if there is a cycle
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(dfs(i, -1, adj, vis)) return false;
            }
        }
        return true;

    }
};
