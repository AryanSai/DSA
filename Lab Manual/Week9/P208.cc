#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

struct Node {
    bool end;
    Node* child[26];
    Node() {
        end = false;
        for (int i = 0; i < 26; i++)
            child[i] = nullptr;
    }
};

class Trie {
public:
    Node* root;
    Trie() { root = new Node(); }

    void insert(string word) {
        Node* curr = root;
        for (char c : word) {
            if (!curr->child[c - 'a']) {
                Node* neww = new Node();
                curr->child[c - 'a'] = neww;
            }
            curr = curr->child[c - 'a'];
        }
        curr->end = true;
    }

    bool search(string word) {
        Node* curr = root;
        for (char c : word) {
            if (!curr->child[c - 'a'])
                return false;
            curr = curr->child[c - 'a'];
        }
        return curr->end;
    }

    bool startsWith(string prefix) {
        Node* curr = root;
        for (char c : prefix) {
            if (!curr->child[c - 'a'])
                return false;
            curr = curr->child[c - 'a'];
        }
        return true;
    }
};
