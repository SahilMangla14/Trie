#include<bits/stdc++.h>
using namespace std;

// TC -> O(Q + N)
// Trie significantly improves the xor queries calculations

// Question Link -> https://leetcode.com/problems/maximum-xor-with-an-element-from-array/description/

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


vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    
    vector<vector<int>> q;
    for(int i=0;i<queries.size();i++){
        q.push_back({queries[i][1],queries[i][0],i});
    }

    sort(q.begin(),q.end());
    sort(nums.begin(),nums.end());
    
    vector<int> ans(q.size(),-1);

    Trie trie;

    int ptr = 0;
    bool flag = false;
    for(int i=0;i<q.size();i++){
        while(ptr < nums.size() && nums[ptr] <= q[i][0]){
            trie.insert(nums[ptr]);
            flag = true;
            ptr++;
        }

        if(flag == false){
            continue;
        }

        int x = q[i][1];

        int value = trie.findMax(x);
        ans[q[i][2]] = value;
    }

    return ans;
}