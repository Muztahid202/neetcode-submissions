class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, unordered_set<int>& vis){
        vis.insert(node);

        for(auto neighbor : adj[node]){
            if(vis.count(neighbor)){
                if(neighbor != parent) return true;
            }
            else if (dfs(neighbor, node, adj, vis)) return true;
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;

        //visited array
        unordered_set<int> vis;

        //construct the graph
        vector<vector<int>> adj(n);
        for(const auto& it : edges){
            int i = it[0];
            int j = it[1];
            adj[i].push_back(j);
            adj[j].push_back(i);
        }

        //detect if there is cycle
        if(dfs(0, -1, adj, vis)) return false;

        //if connected or not
        return vis.size() == n;

    }
};

//no cycle + n-1 edges
