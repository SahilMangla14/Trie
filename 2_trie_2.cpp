#include <bits/stdc++.h> 
using namespace std;

// Question Link -> https://www.codingninjas.com/studio/problems/implement-trie_1387095?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTab=0

class Node {
    public:
    Node* links[26];
    int cw = 0;
    int cp = 0;

    Node(){

        for(int i=0;i<26;i++){
            links[i] = NULL;
        }

        cw = 0;
        cp = 0;
    }
};

class Trie{
    
    private:
    Node* root;

    public:

    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            if(node->links[ch-'a'] == NULL){
                node->links[ch-'a'] = new Node();
            }
            node = node->links[ch-'a'];
            node->cp++;
        }
        node->cw++;
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            if(node->links[ch-'a'] == NULL) return 0;
            node = node->links[ch-'a'];
        }
        return node->cw;
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            if(node->links[ch-'a'] == NULL) return 0;
            node = node->links[ch-'a'];
        }
        return node->cp;
    }

    void erase(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            if(node->links[ch-'a'] == NULL) return;
            node = node->links[ch-'a'];
        }

        node = root;
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            node = node->links[ch-'a'];
            node->cp--;
        }
        node->cw--;
    }
};
