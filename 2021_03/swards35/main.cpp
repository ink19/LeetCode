#include <iostream>
#include <map>

class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
public:
  Node *copyRandomList(Node *head) {
    if (head == NULL) return NULL;
    std::map<Node*, Node*> node_map;
    Node *temp = head;
    while (temp != NULL) {
      auto temp_node = new Node(temp->val);
      node_map.insert({temp, temp_node});
      temp = temp->next;
    }
    for (auto item : node_map) {
      item.second->next = node_map[item.first->next];
      item.second->random = node_map[item.first->random];
    }
    return node_map[head];
  }
};