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
class FindElements {
    public:
        unordered_set<int> d;
        FindElements(TreeNode* root) {
            deque<TreeNode*> l;
            TreeNode* t;
            root->val=0;
            d.insert(root->val);
            l.push_back(root);
            while(l.size()!=0){
                t=l.front();
                if(t->left != nullptr){
                    t->left->val = 2*t->val+1;
                    l.push_back(t->left);
                    d.insert(t->left->val);
                }
                if(t->right != nullptr){
                    t->right->val = 2*t->val+2;
                    l.push_back(t->right);
                    d.insert(t->right->val);
                }
                l.pop_front();
            }
        }
        
        bool find(int target) {
            return d.contains(target);
        }
    };
    
    /**
     * Your FindElements object will be instantiated and called as such:
     * FindElements* obj = new FindElements(root);
     * bool param_1 = obj->find(target);
     */