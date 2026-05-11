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
    unordered_map<Node*, Node*> vis;
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return node;
        }
        Node* root = new Node(node->val);
        vis[node] = root;
        for(auto i: node->neighbors){
            Node* temp = i;
            if(vis.find(i) == vis.end()){
                temp = new Node(i->val);
                vis[i] = temp;
                cloneGraph(i);
            }
            root->neighbors.push_back(vis[i]);
        }
        return root;
    }
};