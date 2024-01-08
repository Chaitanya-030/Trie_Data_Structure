#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    void increaseEnd() {
        cntEndWith++;
    }

    void increasePrefix() {
        cntPrefix++;
    }

    void deleteEnd() {
        cntEndWith--;
    }
    
    void deletePrefix() {
        cntPrefix--;
    }
};


class Trie {
    private :
        Node* root;

    public :

        Trie() {
            root = new Node();
        }

        void insert(string word) {
            Node* node = root;
            for(int i=0;i<word.size();i++) {
                if(!node->containsKey(word[i])) {
                    node->put(word[i], new Node());
                }
                node = node->get(word[i]);
                node->increasePrefix();
            }
            node->increaseEnd();
        }
};