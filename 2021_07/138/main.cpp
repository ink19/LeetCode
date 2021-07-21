#include <vector>
#include <iostream>
#include <map>

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        std::map<Node *, Node *> node_map;
        Node *temp_node = head;
        Node *new_node = new Node(head->val);
        Node *temp_new_node = new_node;
        new_node->random = head->random;
        node_map[head] = new_node;
        while (temp_node->next != NULL) {
            temp_node = temp_node->next;
            temp_new_node->next = new Node(temp_node->val);
            temp_new_node = temp_new_node->next;
            temp_new_node->random = temp_node->random;
            node_map[temp_node] = temp_new_node;
        }
        temp_node = new_node;
        while (temp_node != NULL) {
            if (temp_node->random != NULL) {
                temp_node->random = node_map[temp_node->random];
            }
            temp_node = temp_node->next;
        }
        return new_node;
    }
};