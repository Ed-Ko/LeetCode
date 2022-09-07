
  Definition for a binary tree node.
  public class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode() {}
      TreeNode(int val) { this.val = val; }
      TreeNode(int val, TreeNode left, TreeNode right) {
          this.val = val;
          this.left = left;
          this.right = right;
      }
  }
 
class Solution {
    
    ListListInteger ans = new ArrayListListInteger();
    
    public void BFS(TreeNode root){
        
        QueueTreeNode q = new LinkedListTreeNode();
        q.add(root);
        
        int counter = 1;
        while(!q.isEmpty()){
            
            int next_counter = 0;
            ListInteger cur_vec = new ArrayListInteger();
            for(int i = 0 ; i  counter ; i++){
                TreeNode cur_node = q.remove();
                cur_vec.add(cur_node.val);
                if(cur_node.left != null){
                    q.add(cur_node.left);
                    next_counter++;
                }
                if(cur_node.right != null){
                    q.add(cur_node.right);
                    next_counter++;
                }
            }
            
            ans.add(cur_vec);
            counter = next_counter;
            
        }
        
        return;
        
        
    }
    
    public ListListInteger levelOrder(TreeNode root) {
        if(root != null)
            BFS(root);
        return ans;
    }
}