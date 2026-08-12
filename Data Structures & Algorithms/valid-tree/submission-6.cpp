class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != (n-1)) return false;

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

        //setting the root node to visited
        vis.insert(0);
        queue<pair<int, int>> q;
        q.push({0,-1});

        //doing bfs
        while(!q.empty()){
            pair<int, int> it = q.front();
            q.pop();

            int node = it.first;
            int parent = it.second;

            for(auto neighbor : adj[node]){
                if(!vis.count(neighbor)) {
                    vis.insert(neighbor);
                    q.push({neighbor, node});
                }
                else{
                    if(neighbor != parent) return false;
                }
            }

        }
        //checking if the visited set contains all the element
        return vis.size() == n;
    }
};
