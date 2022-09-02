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
    
    int DFS(TreeNode cur_node, int cur_num){
        
        int tmp_res = 0;
        
        int next_num = cur_num;
        if(cur_node.val >= cur_num){
            next_num = cur_node.val;
            tmp_res++;
        }
        
        if(!Objects.isNull(cur_node.left))
            tmp_res += DFS(cur_node.left, next_num);
        if(!Objects.isNull(cur_node.right))
            tmp_res += DFS(cur_node.right, next_num);
        
        return tmp_res;
        
    }
    
    
    public int goodNodes(TreeNode root) {
        return DFS(root, root.val);
    }
}