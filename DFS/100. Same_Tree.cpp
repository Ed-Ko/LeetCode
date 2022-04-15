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
    
    bool DFS_inorder(TreeNode* cur_node1, TreeNode* cur_node2){
        if(cur_node1 == nullptr && cur_node2 == nullptr)
            return true;
        if((cur_node1 != nullptr && cur_node2 != nullptr)){
            bool check1 = 1;
            bool check2 = 1;
            bool check3 = 1;
            
            if((cur_node1->left != nullptr && cur_node2->left != nullptr) || (cur_node1->left == nullptr && cur_node2->left == nullptr))
                check1 = DFS_inorder(cur_node1->left, cur_node2->left);
            else
                return false;
                
            if(cur_node1->val == cur_node2->val)
                check2 = true;
            else
                return false;
            
            if((cur_node1->right != nullptr && cur_node2->right != nullptr) || (cur_node1->right == nullptr && cur_node2->right == nullptr))
                check3 = DFS_inorder(cur_node1->right, cur_node2->right);
            else
                return false;
            
            return (check1 && check2 && check3);
        }
        return false;
    }
    
//     bool DFS_preorder(TreeNode* cur_node1, TreeNode* cur_node2){
//         if((cur_node1 != nullptr && cur_node2 != nullptr) && (cur_node1 == nullptr && cur_node2 == nullptr)){
//             bool check1 = 1;
//             bool check2 = 1;
//             bool check3 = 1;
            
//             if(cur_node1->val == cur_node2->val)
//                 check2 = true;
//             else
//                 return false;
            
//             if(cur_node1->left != nullptr && cur_node2->left != nullptr)
//                 check1 = DFS_inorder(cur_node1->left, cur_node2->left);
//             else
//                 return false;
            
//             if(cur_node1->right != nullptr && cur_node2->right != nullptr)
//                 check3 = DFS_inorder(cur_node1->right, cur_node2->right);
//             else
//                 return false;
            
//             return (check1 && check2 && check3);
//         }
//         return false;
//     }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool check1 = DFS_inorder(p, q);
        //bool check2 = DFS_preorder(p, q);
        
        return (check1);
    }
};