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
    vector<int> largestValues(TreeNode* root) {
        deque<TreeNode*> lev;
        vector<int> maxArr;
        if(root == NULL){
            return maxArr;
        }
        lev.push_back(root);
        while(!lev.empty()){
            int times = lev.size();
            int maxn = INT_MIN;
            for(int i=0; i<times; ++i){
                TreeNode *tn = lev.front();
                maxn = max(maxn, tn->val);
                if(tn->left != NULL){
                    lev.push_back(tn->left);
                }
                if(tn->right != NULL){
                    lev.push_back(tn->right);
                }
                lev.pop_front();
            }
            maxArr.push_back(maxn);
        }
        return maxArr;
    }
};