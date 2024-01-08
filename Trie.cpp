#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node *links[26]; // because it will point to other Node, hence Node* links
    bool flag = false; // initially initialized with false
    
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node *node) {
        links[ch - 'a'] = node;
    }

    Node *get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
    private :
        Node *root;

    public :
    // constructor : whenever Trie is made, it will first generate a root node
        Trie() {
            root = new Node();
        }

    // it will insert a whole word into a trie making new Node for every word
    // tc - O(len)
        void insert(string word) {
            Node *node = root;
            for(int i=0;i<word.size();i++) {
                if(!node->containsKey(word[i])) {
                    node->put(word[i], new Node());
                }
                // get the node to which word[i] is linked to
                node = node->get(word[i]);
            }

            node->setEnd();
        }

    // returns if the word is in the trie or not
        bool search(string word) {
            Node* node = root;
            for(int i=0;i<word.size();i++) {
                if(!node->containsKey(word[i])) {
                    return false;
                }
                node = node->get(word[i]);
            }
            return node->isEnd();
        }

    // returns whether any of the word has this prefix or not
        bool startswith(string prefix) {
            Node* node = root;
            for(int i=0;i<prefix.size();i++) {
                if(!node->containsKey(prefix[i])) {
                    return false;
                }
                node = node->get(prefix[i]);
            }
            return true;
        }

};
