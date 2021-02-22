#include <iostream>
#include <vector>
#include <map>
using namespace std;


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


class Solution {
public:
    std::map<int, Node*> node_map;
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        auto iter = node_map.find(node->val);
        if (iter != node_map.end()) return (*iter).second;
        Node *new_node = new Node(node->val);
        node_map[node->val] = new_node;
        for (auto &nei: node->neighbors) {
            new_node->neighbors.push_back(cloneGraph(nei));
        }
        return new_node;
    }
};