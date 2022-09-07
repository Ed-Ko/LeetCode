/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    
    public TreeNode prun(TreeNode cur_node){
        
        if(cur_node != null){
            cur_node.left = prun(cur_node.left);
            cur_node.right = prun(cur_node.right);
            if(cur_node.left == null && cur_node.right == null && cur_node.val == 0)
                return null;
        }
        
        return cur_node;
    }
    
    
    public TreeNode pruneTree(TreeNode root) {
        return prun(root);
    }
}