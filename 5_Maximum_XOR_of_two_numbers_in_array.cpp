#include<bits/stdc++.h>
using namespace std;

// TC -> O(32 * N)
// For a single number, it just take O(32) to find the maxiumum xor

// Question Link -> https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/

class Node {
    public:
    Node* links[2];
    bool flag;

    Node(){
        links[0] = NULL;
        links[1] = NULL;
        flag = false;
    }
};

class Trie {
    Node* root;

    public:
    Trie(){
        root = new Node();
    }

    void insert(int num){
        
        Node* node = root;

        for(int i=31;i>=0;i--){
            int bit = num >> i & 1;
            if(node->links[bit] == NULL){
                node->links[bit] = new Node();
            }
            node = node->links[bit];
        }

        node->flag = true;
    }


    int findMax(int num){
        Node* node = root;
        int maxValue = 0;
        for(int i=31;i>=0;i--){
            int bit = num >> i & 1;
            if(node->links[1-bit] != NULL){
                maxValue = maxValue | 1 << i;
                node = node->links[1-bit];
            }
            else{
                node = node->links[bit];
            }
        }

        return maxValue;
    }
};



int findMaximumXOR(vector<int>& nums) {
    Trie trie;
    for(int i=0;i<nums.size();i++){
        trie.insert(nums[i]);
    }

    int ans = 0;
    for(int i=0;i<nums.size();i++){
        int value = trie.findMax(nums[i]);
        ans = max(ans,value);
    }
    return ans;
}
