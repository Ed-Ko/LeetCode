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
    
    boolean preorder(TreeNode cur_node, TreeNode sub){
        
        if(!Objects.isNull(cur_node) && !Objects.isNull(sub) && cur_node.val == sub.val){
            
            boolean left_ans = true;
            boolean right_ans = true;
                
            if(!Objects.isNull(cur_node.left) && !Objects.isNull(sub.left))
                left_ans = preorder(cur_node.left, sub.left);
            else if(Objects.isNull(cur_node.left) && Objects.isNull(sub.left))
                left_ans = true;
            else
                left_ans = false;

            if(!Objects.isNull(cur_node.right) && !Objects.isNull(sub.right))
                right_ans = preorder(cur_node.right, sub.right);
            else if(Objects.isNull(cur_node.right) && Objects.isNull(sub.right))
                right_ans = true;
            else
                right_ans = false;

            return left_ans && right_ans;

        }
        else if(Objects.isNull(cur_node) && Objects.isNull(sub))
            return true;
        
        return false;
        
    }
    
    boolean inorder(TreeNode cur_node, TreeNode sub){
        
        
        if(Objects.isNull(cur_node) && Objects.isNull(sub))
            return true;
        
        else if(!Objects.isNull(cur_node) && !Objects.isNull(sub)){
            
            boolean left_ans = true;
            boolean right_ans = true;

            if(!Objects.isNull(cur_node.left) && !Objects.isNull(sub.left))
                left_ans = inorder(cur_node.left, sub.left);
            else if(Objects.isNull(cur_node.left) && Objects.isNull(sub.left))
                left_ans = true;
            else
                left_ans = false;

            if(cur_node.val != sub.val)
                return false;

            if(!Objects.isNull(cur_node.right) && !Objects.isNull(sub.right))
                right_ans = inorder(cur_node.right, sub.right);
            else if(Objects.isNull(cur_node.right) && Objects.isNull(sub.right))
                right_ans = true;
            else
                right_ans = false;
            
            return left_ans && right_ans;
            
        }
        
        return false;
        
    }
    
    boolean search(TreeNode cur_node, TreeNode subRoot){
        
        if(cur_node.val == subRoot.val){
            if(preorder(cur_node, subRoot) && inorder(cur_node, subRoot))
                return true;
        }
            
        
        boolean left_ans = false;
        boolean right_ans = false;
        
        if(!Objects.isNull(cur_node.left))
            left_ans = search(cur_node.left, subRoot);
        if(!Objects.isNull(cur_node.right))
            right_ans = search(cur_node.right, subRoot);
        
        return left_ans || right_ans;
            
    }
    
    
    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        
        return search(root, subRoot);
        
    }
}