#include <iostream>
#include <string>
#include <map>

using namespace std;


struct TrieTreeNode {
  std::map<char, TrieTreeNode *> data;
  bool leaf = false;
};

class Trie {
public:
  TrieTreeNode root;
  /** Initialize your data structure here. */
  Trie() {}

  /** Inserts a word into the trie. */
  void insert(string word) {
    TrieTreeNode *node = &root;
    const int word_len = word.size();
    for (int loop_i = 0; loop_i < word_len; ++loop_i) {
      if (node->data.count(word[loop_i]) == 1) {
        node = node->data[word[loop_i]];
      } else {
        node->data[word[loop_i]] = new TrieTreeNode;
        node = node->data[word[loop_i]];
      }
    }
    node->leaf = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    TrieTreeNode *node = &root;
    const int word_len = word.size();
    for (int loop_i = 0; loop_i < word_len; ++loop_i) {
      if (node->data.count(word[loop_i]) == 1) {
        node = node->data[word[loop_i]];
      } else {
        return false;
      }
    }
    if (node->leaf == false) return false;
    return true;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    TrieTreeNode *node = &root;
    const int word_len = prefix.size();
    for (int loop_i = 0; loop_i < word_len; ++loop_i) {
      if (node->data.count(prefix[loop_i]) == 1) {
        node = node->data[prefix[loop_i]];
      } else {
        return false;
      }
    }
    return true;
  }
};

