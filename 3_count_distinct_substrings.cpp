#include <bits/stdc++.h> 
using namespace std;

// TC -> O(N * len)
// It removes the factor of logn from brute force solution

// Question Link -> https://www.codingninjas.com/studio/problems/count-distinct-substrings_985292?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTab=0

class Node{
    public:
    Node* links[26];
    bool flag;
    Node(){
        for(int i=0;i<26;i++){
            links[i] = NULL;
        }

        flag = false;
    }
};


class Trie{
    public:
    Node* root;
    int cnt;
    public:
    Trie(){
        root = new Node();
        cnt = 0;
    }

    void insert(string &word){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            if(node->links[ch-'a'] == NULL){
                node->links[ch-'a'] = new Node();
                cnt++;
            }
            node = node->links[ch-'a'];
        }
        node->flag = true;
    }


};
int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    Trie trie;
    for(int i=0;i<s.size();i++){
        string x = "";
        for(int j=i;j<s.size();j++){
            x += s[j];
            trie.insert(x);
        }
    }

    return trie.cnt + 1;
}