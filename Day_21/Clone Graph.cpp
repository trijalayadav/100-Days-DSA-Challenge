class Solution {
public:
    unordered_map<Node*, Node*> visited;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        // If the node is already cloned, return it
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        // Clone the node
        Node* clone = new Node(node->val);
        visited[node] = clone;

        // Clone all the neighbors
        for (auto neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};
