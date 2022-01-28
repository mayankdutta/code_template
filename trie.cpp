#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class TrieNode {
public:
  vector<TrieNode *> child;
  int prefix;
  vector<string> word;

  TrieNode() {
    prefix = 0;
    child = vector<TrieNode *>(26, nullptr);
  }
};

class Trie {
public:
  TrieNode *root;

  Trie() { root = new TrieNode(); }

  void insert(const string &s) {
    TrieNode *curr = root;
    for (const auto &i : s) {
      curr->prefix++;
      int x = i - 'a';
      if (curr->child[x] == nullptr)
        curr->child[x] = new TrieNode();

      curr = curr->child[x];
    }
    curr->word.push_back(s);
  }

  void erase(const string &s) {
    TrieNode *curr = root;
    for (const auto &i : s) {
      curr->prefix--;
      int x = i - 'a';
      if (curr->child[x] == nullptr) {
        curr = curr->child[x];
      }
    }
  }

  bool find(const string &s) {
    TrieNode *curr = root;
    for (const auto &i : s) {
      int x = i - 'a';
      if (curr->child[x] == nullptr) {
        return false;
      }
    }
    return !curr->word.empty();
  }
  bool find_prefix(const string &s) {
    TrieNode *curr = root;
    for (const auto &i : s) {
      int x = i - 'a';
      if (curr->child[x] == nullptr) {
        return false;
      }
    }
    return true;
  }
};
