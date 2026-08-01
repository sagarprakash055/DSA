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
private:
    // We create a helper function to handle the recursion
    // Notice we pass 'result' by reference (&) so all recursive calls share the same list
    void traverse(TreeNode* node, vector<int>& result) {
        // Here is your exact instinct: the base case!
        if (node == nullptr) {
            return;
        }
        
        // 1. Visit the Root
        result.push_back(node->val);
        
        // 2. Visit the Left subtree
        traverse(node->left, result);
        
        // 3. Visit the Right subtree
        traverse(node->right, result);
    }
    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result; // Create the empty list
        traverse(root, result); // Start the traversal
        return result; // Return the final populated list
    }
};