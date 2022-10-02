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
    
    Set<Integer> vec = new HashSet<Integer>();
    
    boolean recur(TreeNode cur_node, int target){
        
        if(cur_node == null)
            return false;
    
        if(recur(cur_node.left, target))
            return true;    
        if(vec.contains(target - cur_node.val))
            return true;
        
        vec.add(cur_node.val);
        if(recur(cur_node.right, target))
            return true;
        return false;
    }
    
    public boolean findTarget(TreeNode root, int k) {
        
        return recur(root, k);
    }
}