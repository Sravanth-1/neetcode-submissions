/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* Build(int prestart, int preend, int instart, int inend, vector<int>& preorder, vector<int>& inorder, unordered_map<int, int> & mp){
        if(prestart > preend || instart > inend){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[prestart]);
        int index = mp[root->val];
        int leftlen = index - instart;
        root->left = Build(prestart+1,prestart+leftlen, instart, index-1, preorder, inorder, mp);
        root->right = Build(prestart+leftlen+1, preend, index+1, inend, preorder, inorder, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for(int i = 0; i< inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        return Build(0, preorder.size()-1, 0, inorder.size()-1,preorder, inorder, mp);
    }
};


