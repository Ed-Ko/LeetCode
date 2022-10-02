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
    
    public boolean recur(TreeNode cur_node, TreeNode max_node, TreeNode min_node){
        
        if(cur_node == null)
            return true;
        
        if(max_node != null && cur_node.val >= max_node.val)
            return false;
        
        if(min_node != null && cur_node.val <= min_node.val)
            return false;
        
        return recur(cur_node.left, cur_node, min_node) && recur(cur_node.right, max_node, cur_node);
        
    }
    
    public boolean isValidBST(TreeNode root) {
        return recur(root, null, null);
    }
}