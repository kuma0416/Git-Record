// TC, SC: O(N)
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
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
            TreeNode* base=new TreeNode(0);
            int pLen=preorder.size(), poLen=postorder.size();
            int poIdx=0;
            deque<TreeNode*> d={base};
            TreeNode* tn;
            TreeNode* last;
            for(int i=0; i<pLen; ++i){
                last=d.back();
                tn=new TreeNode(preorder[i]);
                if(preorder[i]==postorder[poIdx]){
                    poIdx++;
                    while(poIdx < postorder.size() && d.back()->val == postorder[poIdx]){
                        d.pop_back();
                        poIdx++;
                    }
                } else {
                    d.push_back(tn);
                }
                if(last->left == nullptr){
                    last->left=tn;
                } else {
                    last->right=tn;
                }
            }
            return base->left;
        }
    };