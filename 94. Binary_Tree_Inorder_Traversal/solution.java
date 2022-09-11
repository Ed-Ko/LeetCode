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
    
    List<Integer> ans = new ArrayList<Integer>();
    
    public void traverse(TreeNode cur_node){
        
        if(cur_node.left != null)
            traverse(cur_node.left);
        
        ans.add(cur_node.val);
        
        if(cur_node.right != null)
            traverse(cur_node.right);
        
        return;
    }
    
    public List<Integer> inorderTraversal(TreeNode root) {
        if(root != null)
            traverse(root);
        return ans;    
    }
}