#include <bits/stdc++.h> 
using namespace std;

// TC -> O(N * len)
// It removes the factor of logn from brute force solution

// Question Link -> https://www.codingninjas.com/studio/problems/complete-string_2687860?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTab=0

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
    private:
    Node* root;
    public:
    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            if(node->links[ch-'a'] == NULL){
                node->links[ch-'a'] = new Node();
            }
            node = node->links[ch-'a'];
        }
        node->flag = true;
    }

    bool isAllPrefixExists(string &word){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            if(node->links[ch-'a'] == NULL) return false;
            node = node->links[ch-'a'];
            if(node->flag == false) return false;
        }
        return true;
    }
};


string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie trie;
    for(auto &x:a){
        trie.insert(x);
    }

    string ans = "";
    for(int i=0;i<a.size();i++){
        if(trie.isAllPrefixExists(a[i]) == true && (ans == "" || ans.size() <= a[i].size())){
            if(ans == "") ans = a[i];
            else if(ans.size() < a[i].size()) ans = a[i];
            else{
                bool flag = false;
                for(int j=0;j<ans.size();j++){
                    if(ans[j] > a[i][j]){
                        flag = true;
                        break;
                    }
                }
                if(flag){
                    ans = a[i];
                }
            }
        }
    }

    if(ans == "") return "None";

    return ans;

}