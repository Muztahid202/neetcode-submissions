/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& cloned){
        auto it = cloned.find(node);

        if(it != cloned.end()){
            return it->second;
        }

        Node* newNode = new Node(node->val);
        cloned[node] = newNode;

        for(Node* neighbor : node->neighbors){
            newNode->neighbors.push_back(dfs(neighbor, cloned));
        }
        return newNode;
    }
    Node* cloneGraph(Node* node) {
        if(!node) return node;

        unordered_map<Node*, Node*> cloned;
        return dfs(node, cloned);
    }
};
