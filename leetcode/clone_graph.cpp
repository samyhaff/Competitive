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
    Node* cloneGraph(Node* node) {
        unordered_map<Node *, Node *> map;
        stack<Node *> to_process;
        Node *current, *clone;

        if (!node) return NULL;

        to_process.push(node);
        clone = new Node;
        clone->val = node->val;
        clone->neighbors = vector<Node *>();
        map[node] = clone;

        while (!to_process.empty()) {
            current = to_process.top(); to_process.pop();
            clone = map[current];
            for (Node *neighbor: current->neighbors) {
                if (map.find(neighbor) != map.end()) {
                    clone->neighbors.push_back(map[neighbor]);
                } else {
                    Node *new_node = new Node;
                    new_node->val = neighbor->val;
                    new_node->neighbors = vector<Node *>();
                    clone->neighbors.push_back(new_node);
                    to_process.push(neighbor);
                    map[neighbor] = new_node;
                }
            }
        }

        return map[node];
    }
};
