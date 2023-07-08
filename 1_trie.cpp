#include<bits/stdc++.h>
using namespace std;

// Question Link -> https://www.codingninjas.com/studio/problems/implement-trie_631356

class Node {
    public:
    Node* links[26];
    bool flag;

    Node(){
        for(int i=0;i<26;i++){
            links[i] = NULL;
        }
        flag = false;
    }

    bool containsKey(char ch){
        if(links[ch-'a'] == NULL) return false;
        else return true;
    }

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }

};


class Trie {

public:

    /** Initialize your data structure here. */
    Node* root;
    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->links[word[i]-'a'];
        }

        node->flag = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])) return false;
            node = node->links[word[i]-'a'];
        }

        return node->flag;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containsKey(prefix[i])) return false;
            node = node->links[prefix[i]-'a'];
        }

        return true;
    }
};